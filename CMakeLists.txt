cmake_minimum_required(VERSION 3.5)
project(google-test)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)

# Add subdirectory
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/googletest)
add_subdirectory(application)
add_subdirectory(test)