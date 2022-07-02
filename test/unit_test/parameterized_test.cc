#include <gtest/gtest.h>

#include "validator.hpp"

// Validator (5, 10)
class ValidatorFixture : public testing::TestWithParam<std::tuple<int, bool>>
{
public:

protected:
    Validator validator_{5, 10};
};

// In order to use the test fixture with parameters, we have to use TEST_P
TEST_P(ValidatorFixture, TestInRange)
{
    std::tuple<int, bool> tuple = GetParam();
    int param = std::get<0>(tuple);
    bool expected_value = std::get<1>(tuple);

    bool is_inside = validator_.InRange(param);

    ASSERT_EQ(expected_value, is_inside);
}

// Generate test case, values in 5~10
INSTANTIATE_TEST_CASE_P(InRangeTrue, ValidatorFixture, testing::Values(
    std::make_tuple(4,false),
    std::make_tuple(3,false),
    std::make_tuple(5,true),
    std::make_tuple(7,true), 
    std::make_tuple(8,true), 
    std::make_tuple(5,true), 
    std::make_tuple(9,true), 
    std::make_tuple(10,true),
    std::make_tuple(11,false)));