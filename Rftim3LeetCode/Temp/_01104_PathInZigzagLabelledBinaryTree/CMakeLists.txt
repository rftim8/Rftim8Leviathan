cmake_minimum_required(VERSION 3.5.0)
project(_01104_PathInZigzagLabelledBinaryTree VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_01104_PathInZigzagLabelledBinaryTree main.cpp)

target_link_libraries(_01104_PathInZigzagLabelledBinaryTree gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
