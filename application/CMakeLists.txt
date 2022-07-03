cmake_minimum_required(VERSION 3.5)

# project
set(PROJECT ${CMAKE_PROJECT_NAME})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

# include project directories
include_directories(
  include
)

# set sources
set(SRC_FILES
  src/main.cc
  src/simple_function.cc
  src/account.cc
  src/number_generator.cc
  src/validator.cc

  src/database_connection/database_connection.cc
  src/database_connection/employee_manager.cc
)

# build
add_executable(${PROJECT}_exe ${SRC_FILES})
add_library(${PROJECT}_lib STATIC ${SRC_FILES})
# target_link_libraries()
