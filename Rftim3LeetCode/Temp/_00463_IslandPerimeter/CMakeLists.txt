cmake_minimum_required(VERSION 3.5.0)
project(_00463_IslandPerimeter VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_00463_IslandPerimeter main.cpp)

target_link_libraries(_00463_IslandPerimeter gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
