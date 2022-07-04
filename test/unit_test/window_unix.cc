#include <gtest/gtest.h>

TEST(UnixSuite, UnixPass)
{
    #ifdef __WIN32
    FAIL();
    #else
    SUCCEED();
    #endif
}

// TEST(WindowSuite, WindowPass)
// {
//     #ifdef __WIN32
//     SUCCEED();
//     #else
//     FAIL();
//     #endif
// }

