#include "gtest/gtest.h"

int main(int argc, char** argv)
{
// If you want to use filter, uncomment below sections
#ifdef __WIN32
    // testing::GTEST_FLAG(filter) = "WindowSuite.*";
#else
    // testing::GTEST_FLAG(filter) = "UnixSuite.*";
#endif
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}