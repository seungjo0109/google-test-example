#include <map>

#include "database_connection/employee_manager.hpp"

EmployeeManager::EmployeeManager(DatabaseConnection *db_connection): db_connection_{db_connection}
{
    db_connection_->Connect();
}

EmployeeManager::~EmployeeManager()
{
    db_connection_->Disconnect();
}


float EmployeeManager::GetSalary(int employee_id) const
{
    return db_connection_->GetSalary(employee_id); 
}
  
void EmployeeManager::SetSalary(int employee_id, float new_salary)
{
    db_connection_->UpdateSalary(employee_id, new_salary);
}
  
std::map<std::string, float> EmployeeManager::VectorToMap(std::vector<Employee> const& employees) const
{
    std::map<std::string, float> result;
    for(Employee const& employee : employees)
    {
        result[employee.name] = employee.salary;
    }
    return result;
}

std::map<std::string,float> EmployeeManager::GetSalariesGreater(float low) const
{
    return VectorToMap(db_connection_->GetSalariesRange(low));
  
}
std::map<std::string,float> EmployeeManager::GetSalariesBetween(float low, float high) const
{
    return VectorToMap(db_connection_->GetSalariesRange(low, high));
}
