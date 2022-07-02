#include <gtest/gtest.h>

#include "application.hpp"

/* Unit test AAA structure */
TEST(TestCountPositives, BasicTest)
{
    // Arrange section
    std::vector<int> input_vector{-1, 2, 3, -4, 5, 6, 7};

    // Act section
    int count = CountPositives(input_vector);

    // Assert
    // unit test convention: expected value is first argument.
    ASSERT_EQ(5, count);    // Fatal
    EXPECT_EQ(5, count);    // Non-fatal
}

// Test suite(first paramter) is basically a collection of related tests.
TEST(TestCountPositives, EmptyVecotrTest)
{
    // Arrange section
    std::vector<int> input_vector{};

    // Act section
    int count = CountPositives(input_vector);

    // Assert
    // unit test convention: expected value is first argument.
    ASSERT_EQ(0, count);    // Fatal
    EXPECT_EQ(0, count);    // Non-fatal
}

TEST(TestCountPositives, AllNegativeTest)
{
    // Arrange section
    std::vector<int> input_vector{-1, -2, -3, -4, -5};

    // Act section
    int count = CountPositives(input_vector);

    // Assert
    // unit test convention: expected value is first argument.
    ASSERT_EQ(0, count);    // Fatal
    EXPECT_EQ(0, count);    // Non-fatal
}

/* String unit test */
TEST(ToUpperTest, BasicTest)
{
    // Arrange
    char input_string[] = "Hello world";

    // Act
    ToUpper(input_string);

    // Assert
    // ASSERT_EQ("HELLO WORLD", input_string);     // Test failed: compare two pointers of string
    ASSERT_STREQ("HELLO WORLD", input_string);
    EXPECT_STREQ("HELLO WORLD", input_string);
    ASSERT_STRCASEEQ("Hello world", input_string);
    EXPECT_STRCASEEQ("Hello world", input_string);
}

/* Exception test */
TEST(CustomSqrtTest, NegativeArgumentTest)
{
    // Arrange
    double input_value = -1.0;

    ASSERT_THROW(CustomSqrt(input_value), std::runtime_error);
    ASSERT_ANY_THROW(CustomSqrt(input_value));
}

TEST(CustomSqrtTest, PositiveArgumentTest)
{
    // Arrange
    double input_value = 9.0;

    ASSERT_NO_THROW(CustomSqrt(input_value));
}