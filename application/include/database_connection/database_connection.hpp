#pragma once

#include <iostream>
#include <functional>
#include <string>
#include <vector>

#include "employee.hpp"

//interface because we might subclass it
//example: IOracleDatabaseConnectionManager, ISQLDatabaseConnectionManager
class DatabaseConnection
{
public:
    using Callback = std::function<void()>;

    DatabaseConnection(std::string server_address);
    
    virtual float GetSalary(int id) const = 0;  // SELECT * FROM employees WHERE id=...
    virtual void UpdateSalary(int id, float new_salary) = 0;

    virtual std::vector<Employee> GetSalariesRange(float low) const = 0;    //just greater than low
    virtual std::vector<Employee> GetSalariesRange(float low, float high) const = 0;

    virtual void Connect();
    virtual void Disconnect();

    void SetOnConnect(Callback on_connect_callback);

protected:
    std::string server_address_;
    Callback on_connect_callback_;

private:
    virtual void IncreaseConnectionCount(){ std::cout << "Increase connection count!\n"; }

};
