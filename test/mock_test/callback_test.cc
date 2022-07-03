#include <functional>
#include <map>
#include <vector>

#include <gmock/gmock.h>

#include "database_connection/database_connection.hpp"
#include "database_connection/employee.hpp"
#include "database_connection/employee_manager.hpp"


class MockDatabaseConnectionCallback : public DatabaseConnection
{
public:
    MockDatabaseConnectionCallback(std::string server_address);

    /* Current MOCK_METHOD */
    // MOCK_METHOD(void, Connect, ());  // We sholdn't mock Connect to test callback
    MOCK_METHOD(void, Disconnect, ());

    MOCK_METHOD(float, GetSalary, (int), (const));
    MOCK_METHOD(void, UpdateSalary, (int, float));

    MOCK_METHOD(std::vector<Employee>, GetSalariesRange, (float), (const));
    MOCK_METHOD(std::vector<Employee>, GetSalariesRange, (float, float), (const));

    MOCK_METHOD(void, IncreaseConnectionCount, (), (override));
};

MockDatabaseConnectionCallback::MockDatabaseConnectionCallback(std::string server_address) : DatabaseConnection(server_address)
{

}

/* ~~~~~~~~~~~~~~~~~~~~~~~~
    Private function test 
~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
TEST(TestEmployeeManager, PrivateTest)
{
    MockDatabaseConnectionCallback db_connection("dummy_connection");
    
    EXPECT_CALL(db_connection, IncreaseConnectionCount());
    db_connection.Connect();    // IncreaseConnectionCount is called in Connect()
}

/* ~~~~~~~~~~~~~~~~~
    Callback test 
~~~~~~~~~~~~~~~~~~~*/
TEST(TestEmployeeManager, CallbackTest)
{
    MockDatabaseConnectionCallback db_connection("dummy_connection");
    testing::MockFunction<void()> mock_function;
    db_connection.SetOnConnect(mock_function.AsStdFunction());

    EXPECT_CALL(mock_function, Call());

    db_connection.Connect();
}