cmake_minimum_required(VERSION 3.0)

project(OCC VERSION 1.0.0)

include(CTest)
set(CMAKE_BUILD_TYPE Debug)

# Enable Coverage Tests
SET(CMAKE_CXX_FLAGS  "-std=c++20 -DOCTETOS_CC_V1_TDD")

# Show all warning messages
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

INCLUDE_DIRECTORIES(../)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()

#add_subdirectory(1)