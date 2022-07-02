#include <iostream>

#include <gtest/gtest.h>

#include "account.hpp"

class AccountTestFixture : public testing::Test
{
public:
    AccountTestFixture();
    virtual ~AccountTestFixture() override;

    void SetUp() override;
    void TearDown() override;
    // These methods need to be static
    static void SetUpTestCase();
    static void TearDownTestCase();
protected:
    Account account_;
};

AccountTestFixture::AccountTestFixture()
{
    std::cout << "AccountTestFixture constructor called\n";
}

AccountTestFixture::~AccountTestFixture()
{
    std::cout << "AccountTestFixture destructor called\n";
}

void AccountTestFixture::SetUp()
{
    std::cout << "AccountTestFixture SetUp() called\n";

    // Test fixture SetUp
    account_.Deposit(10.0);
}

void AccountTestFixture::SetUpTestCase()
{
    std::cout << "AccountTestFixture SetUpTestCase() called\n";
}

void AccountTestFixture::TearDown()
{
    std::cout << "AccountTestFixture TearDown() called\n";
}

void AccountTestFixture::TearDownTestCase()
{
    std::cout << "AccountTestFixture TearDownTestCase() called\n";
}


// In order to use the test fixture, we have to use TEST_F
// First parameter, which is the test suite has to be the name of the test fixture
TEST_F(AccountTestFixture, TestDeposit)
{
    ASSERT_EQ(10.0, account_.GetBalance());
}

TEST_F(AccountTestFixture, TestWithdraw)
{
    account_.Withdraw(3.0);

    ASSERT_EQ(7.0, account_.GetBalance());
}

TEST_F(AccountTestFixture, TestWithdrawInsufficientFunds)
{
    ASSERT_THROW(account_.Withdraw(20.0), std::runtime_error);
}

TEST_F(AccountTestFixture, TestTransfer)
{
    Account to;
    account_.Transfer(to, 5.0);

    ASSERT_EQ(5.0, account_.GetBalance());
    ASSERT_EQ(5.0, to.GetBalance());
}

TEST_F(AccountTestFixture, TestTransferInsufficientFunds)
{
    Account to;

    ASSERT_THROW(account_.Transfer(to, 20.0), std::runtime_error);
}
