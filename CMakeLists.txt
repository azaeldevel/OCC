cmake_minimum_required(VERSION 3.0)

project(OCC VERSION 1.0.0)

# set(CMAKE_BUILD_TYPE Debug)

# Enable Coverage Tests
SET(CMAKE_CXX_FLAGS  "-std=c++20 -DOCTETOS_CC_V1_TDD")

INCLUDE_DIRECTORIES(../)

if(CMAKE_BUILD_TYPE)
  include(CTest)
  add_subdirectory(tests)
endif()

#add_subdirectory(1)