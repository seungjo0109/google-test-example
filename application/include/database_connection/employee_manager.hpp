#pragma once

#include <map>
#include <vector>
#include <string>

#include "employee.hpp"
#include "database_connection.hpp"

class EmployeeManager
{
public:
    EmployeeManager(DatabaseConnection *db_connection);
    ~EmployeeManager();

    void SetSalary(int employee_id, float new_salary);
    float GetSalary(int employee_id) const;
    
    std::map<std::string,float> GetSalariesGreater(float low) const;
    std::map<std::string,float> GetSalariesBetween(float low, float high) const;
  
private:
    std::map<std::string, float> VectorToMap(std::vector<Employee> const& employees) const;

private:
    DatabaseConnection  *db_connection_;
};