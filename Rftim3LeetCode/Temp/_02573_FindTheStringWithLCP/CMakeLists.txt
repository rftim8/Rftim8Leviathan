cmake_minimum_required(VERSION 3.5.0)
project(_02573_FindTheStringWithLCP VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_02573_FindTheStringWithLCP main.cpp)

target_link_libraries(_02573_FindTheStringWithLCP gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
