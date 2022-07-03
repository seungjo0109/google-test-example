#include <gmock/gmock.h>

#include "number_generator.hpp"

TEST(VectorTest, ElmentsAreTest)
{
    // 0, 1, 2, 0, 1
    std::vector<int> v = GenerateNumbers(5, 3);
    
    ASSERT_THAT(v, testing::ElementsAre(0,1,2,0,1));
}

TEST(VectorTest, RangeTest)
{
    std::vector<int> v = GenerateNumbers(5, 3);

    ASSERT_THAT(v, testing::Each(testing::AllOf(testing::Ge(0), testing::Lt(3))));
}