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
  src/application.cc
)

# build
add_executable(${PROJECT}_exe ${SRC_FILES})
add_library(${PROJECT}_lib STATIC ${SRC_FILES})
# target_link_libraries()
