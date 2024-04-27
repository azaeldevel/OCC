cmake_minimum_required(VERSION 3.0)

project(OCC VERSION 1)

# set(CMAKE_BUILD_TYPE Debug)

set(OCC_SUFIX "-dbg")

# Enable Coverage Tests
SET(CMAKE_CXX_FLAGS  "-std=c++20 -DOCTETOS_CC_V1_TDD")

INCLUDE_DIRECTORIES(../)
INCLUDE_DIRECTORIES(1)
INCLUDE_DIRECTORIES($(CMAKE_BINARY_DIR)/1/)


add_subdirectory(1)


if(CMAKE_BUILD_TYPE)
  include(CTest)
  add_subdirectory(tests)
endif()
