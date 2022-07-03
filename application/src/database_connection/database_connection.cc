#include <iostream>

#include "database_connection/database_connection.hpp"

DatabaseConnection::DatabaseConnection(std::string server_address) : server_address_{server_address}
{
}

void DatabaseConnection::Connect()
{
    std::cout << "Connecting to database server " << server_address_ << "\n";
    //initialize real DB connection
    if(on_connect_callback_ != nullptr)
    {
        std::cout << "on_connect_callback called\n"; 
        on_connect_callback_();
    }

    // Private function test
    IncreaseConnectionCount();
}

void DatabaseConnection::Disconnect()
{
    std::cout << "Disconnecting from database\n";
    //close the real connection
}

void DatabaseConnection::SetOnConnect(Callback on_connect_callback)
{
    on_connect_callback_ = on_connect_callback;
}