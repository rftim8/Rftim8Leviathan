cmake_minimum_required(VERSION 3.5.0)
project(_00251_Flatten2DVector VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_00251_Flatten2DVector main.cpp)

target_link_libraries(_00251_Flatten2DVector gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
