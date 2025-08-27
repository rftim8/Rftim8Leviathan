cmake_minimum_required(VERSION 3.5.0)
project(_00976_LargestPerimeterTriangle VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_00976_LargestPerimeterTriangle main.cpp)

target_link_libraries(_00976_LargestPerimeterTriangle gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
