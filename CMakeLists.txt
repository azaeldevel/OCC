cmake_minimum_required(VERSION 3.0)

project(OCC VERSION 1)

SET(CMAKE_CXX_FLAGS  "-std=c++20 -Wall -pedantic")

INCLUDE_DIRECTORIES(../)
INCLUDE_DIRECTORIES(1)
INCLUDE_DIRECTORIES($(CMAKE_BINARY_DIR)/1/)


add_subdirectory(1)

# Enable Coverage Tests
if(CMAKE_BUILD_TYPE)
  SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DOCTETOS_CC_V1_TDD -g ")
  include(CTest)
  add_subdirectory(tests)
endif()
