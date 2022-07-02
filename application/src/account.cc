#include <stdexcept>

#include "account.hpp"

Account::Account() : balance_{0.0}
{

}

void Account::Deposit(double sum)
{
    balance_ += sum;
}

void Account::Withdraw(double sum)
{
    if(balance_ < sum){
        throw std::runtime_error("Insufficient funds");
    }
    balance_ -= sum;
}

double Account::GetBalance() const
{
    return balance_;
}

void Account::Transfer(Account& to, double sum)
{
    Withdraw(sum);  // will throw an error if not enough
    to.Deposit(sum);
}
