#include "gtest/gtest.h"
#include "test_code.hpp"


TEST(TestCas1, SimpleFunctionTest){
    ASSERT_TRUE(ReturnTrue());      // Is it true?
    ASSERT_FALSE(ReturnFalse());    // Is it false?
}

TEST(TestCase2, SimpleFunctionTest){
    EXPECT_EQ(SimpleAdd(1,2), 3);   // Equal
    EXPECT_NE(SimpleAdd(1,2), 2);   // Not equal
}

TEST(TestCase3, SimpleFunctionTest){
    ASSERT_STREQ(SimpleStringConcat("hello ", "world").c_str(), "hello world");         // Is string equal?
    ASSERT_STRNE(SimpleStringConcat("hello ", "world").c_str(), "Hello world");         // Isn't string equal?
    ASSERT_STRCASEEQ(SimpleStringConcat("hello ", "world").c_str(), "Hello world");     // Is string equal? (ignoring case)
    ASSERT_STRCASENE(SimpleStringConcat("hello ", "world").c_str(), "Hallo world");     // Isn't string equal? (ignoring case)
}