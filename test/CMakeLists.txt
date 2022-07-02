cmake_minimum_required(VERSION 3.5)

set(BINARY ${CMAKE_PROJECT_NAME}_test)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.hpp *.cc)
set(SOURCES ${TEST_SOURCES})

include_directories(
  ${CMAKE_SOURCE_DIR}/application/include
)

add_executable(${BINARY}
  ${TEST_SOURCES}
)
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)