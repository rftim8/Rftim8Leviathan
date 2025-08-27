cmake_minimum_required(VERSION 3.5.0)
project(_01220_CountVowelsPermutation VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_01220_CountVowelsPermutation main.cpp)

target_link_libraries(_01220_CountVowelsPermutation gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
