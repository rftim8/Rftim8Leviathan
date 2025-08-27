cmake_minimum_required(VERSION 3.5.0)
project(_02667_CreateHelloWorldFunction VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_02667_CreateHelloWorldFunction main.cpp)

target_link_libraries(_02667_CreateHelloWorldFunction gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
