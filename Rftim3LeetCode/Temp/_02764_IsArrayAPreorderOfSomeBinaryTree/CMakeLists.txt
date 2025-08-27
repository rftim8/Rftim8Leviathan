cmake_minimum_required(VERSION 3.5.0)
project(_02764_IsArrayAPreorderOfSomeBinaryTree VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_02764_IsArrayAPreorderOfSomeBinaryTree main.cpp)

target_link_libraries(_02764_IsArrayAPreorderOfSomeBinaryTree gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
