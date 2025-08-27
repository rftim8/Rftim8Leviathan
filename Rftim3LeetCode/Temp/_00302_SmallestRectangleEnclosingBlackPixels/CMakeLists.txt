cmake_minimum_required(VERSION 3.5.0)
project(_00302_SmallestRectangleEnclosingBlackPixels VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_00302_SmallestRectangleEnclosingBlackPixels main.cpp)

target_link_libraries(_00302_SmallestRectangleEnclosingBlackPixels gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
