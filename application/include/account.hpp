#pragma once

class Account
{
public:
    Account();
    void Deposit(double sum);
    void Withdraw(double sum);
    double GetBalance() const;
    void Transfer(Account& to, double sum);
private:
    double balance_;
};