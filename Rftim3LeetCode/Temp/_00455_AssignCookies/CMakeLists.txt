cmake_minimum_required(VERSION 3.5.0)
project(_00455_AssignCookies VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_00455_AssignCookies main.cpp)

target_link_libraries(_00455_AssignCookies gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
