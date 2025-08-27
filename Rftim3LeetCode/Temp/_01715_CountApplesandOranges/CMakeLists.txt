cmake_minimum_required(VERSION 3.5.0)
project(_01715_CountApplesandOranges VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_01715_CountApplesandOranges main.cpp)

target_link_libraries(_01715_CountApplesandOranges gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
