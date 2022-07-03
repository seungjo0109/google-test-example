#include <functional>
#include <map>
#include <vector>

#include <gmock/gmock.h>

#include "database_connection/database_connection.hpp"
#include "database_connection/employee.hpp"
#include "database_connection/employee_manager.hpp"


class MockDatabaseConnection : public DatabaseConnection
{
public:
    MockDatabaseConnection(std::string server_address);

    /* Current MOCK_METHOD */
    MOCK_METHOD(void, Connect, ());
    MOCK_METHOD(void, Disconnect, ());

    MOCK_METHOD(float, GetSalary, (int), (const));
    MOCK_METHOD(void, UpdateSalary, (int, float));

    MOCK_METHOD(std::vector<Employee>, GetSalariesRange, (float), (const));
    MOCK_METHOD(std::vector<Employee>, GetSalariesRange, (float, float), (const));

    // This method does not exist in the superclass, it doesn't really have to.
    // What we just wrote is like writing an empty function with all the functionalities 
    // that mocks have like being able to check.
    MOCK_METHOD((std::map<std::string, int>), Something, ());

    /* Legacy MOCK_METHOD */
    // MOCK_METHOD0(Connect, void());
    // MOCK_METHOD0(Disconnect, void());

    // MOCK_CONST_METHOD1(GetSalary, float(int));
    // MOCK_METHOD2(UpdateSalary, void(int, float));

    // MOCK_CONST_METHOD1(GetSalariesRange, std::vector<Employee>(float));
    // MOCK_CONST_METHOD2(GetSalariesRange, std::vector<Employee>(float, float));

    void FreeMemberFunction(std::string param)
    {
        std::cout << "Free member function with param: " << param << "\n";
        throw std::runtime_error("dummy exceoption");
    }
};

MockDatabaseConnection::MockDatabaseConnection(std::string server_address) : DatabaseConnection(server_address)
{

}

/* ~~~~~~~~~~~~~~~~~~~~~~~
    Invoking actions test 
~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Define runtime_error throwing action
ACTION(TestThrow)
{
    std::cout << "Throwing an error\n";
    throw std::runtime_error("dummy_error");
}

TEST(TestEmployeeManager, TestConnectionErrorAction)
{
    MockDatabaseConnection db_connection("dummy_connection");
    EXPECT_CALL(db_connection, Connect()).WillOnce(TestThrow());    // Throw ACTION(throw std::runtime_error)

    ASSERT_THROW(EmployeeManager employ_manager(&db_connection), std::runtime_error);
}

// Define free function to be invoked
void FreeFunction()
{
    std::cout << "Free function\n";
    throw std::runtime_error("dummy exceoption");
}

// Test with invoking actions
TEST(TestEmployeeManager, TestConnectionErrorInvoke)
{
    MockDatabaseConnection db_connection("dummy_connection");
    
    // Invoke FreeFunction(throw std::runtime_error)
    // EXPECT_CALL(db_connection, Connect()).WillOnce(testing::Invoke(FreeFunction));
    
    // We can also invoke member function by using std::bind
    // auto bound_mehtod = std::bind(&MockDatabaseConnection::FreeMemberFunction, &db_connection, "parameters");
    // EXPECT_CALL(db_connection, Connect()).WillOnce(testing::InvokeWithoutArgs(bound_mehtod));
    
    // We can also invoke lambda function
    EXPECT_CALL(db_connection, Connect()).WillOnce(testing::Invoke(
        [](){
            std::cout << "We can also invoke lambda function\n";
            throw std::runtime_error("dummy_error"); 
        }));

    ASSERT_THROW(EmployeeManager employ_manager(&db_connection), std::runtime_error);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~
    EmployeeManager test 
~~~~~~~~~~~~~~~~~~~~~~~~~~*/
TEST(TestEmployeeManager, TestConnection)
{
    MockDatabaseConnection db_connection("dummy_connection");
    EXPECT_CALL(db_connection, Connect());
    EXPECT_CALL(db_connection, Disconnect());

    EmployeeManager employee_manager(&db_connection);
}

TEST(TestEmployeeManager, TestUpdateSalary)
{
    MockDatabaseConnection db_connection("dummy_connection");
    EXPECT_CALL(db_connection, Connect());
    EXPECT_CALL(db_connection, Disconnect());
    EXPECT_CALL(db_connection, UpdateSalary(50, 6000)).Times(1);    // We can check how many times this method is called.
    // EXPECT_CALL(db_connection, UpdateSalary(testing::_, testing::_)).Times(1);  // If we don't care with what values, using testing::_

    EmployeeManager employee_manager(&db_connection);

    employee_manager.SetSalary(50, 6000);
}

TEST(TestEmployeeManager, TestGetSalary)
{
    const int employee_id = 50;
    const float salary = 6000.0;

    MockDatabaseConnection db_connection("dummy_connection");
    EXPECT_CALL(db_connection, Connect());
    EXPECT_CALL(db_connection, Disconnect());
    EXPECT_CALL(db_connection, GetSalary(testing::_)).WillOnce(testing::Return(salary));


    EmployeeManager employee_manager(&db_connection);

    float returned_salary = employee_manager.GetSalary(50);
    ASSERT_EQ(salary, returned_salary);
}

/* ~~~~~~~~~~~~~~~~~
    Matcher test 
~~~~~~~~~~~~~~~~~~*/
TEST(TestEmployeeManager, TestGetSalaryInRange)
{
    const float low = 3500.0, high = 7500.0;
    std::vector<Employee> returned_vector{ Employee{1, 5000.0, "John"},
                                           Employee{1, 7000.0, "David"},
                                           Employee{1, 4000.0, "Alex"}};

    MockDatabaseConnection db_connection("dummy_connection");
    EXPECT_CALL(db_connection, Connect());
    EXPECT_CALL(db_connection, Disconnect());
    EXPECT_CALL(db_connection, GetSalariesRange(low, high)).WillOnce(testing::Return(returned_vector));

    EmployeeManager employee_manager(&db_connection);

    std::map<std::string, float> returned_map = employee_manager.GetSalariesBetween(low, high);

    for(auto it=returned_map.begin(); it!=returned_map.end(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
        ASSERT_THAT(it->second, testing::AllOf(testing::Gt(low), testing::Lt(high)));              // Test macher
        ASSERT_THAT(it->second, testing::AnyOf(testing::Gt(low), testing::Lt(high)));              // Test macher 
    }

}


