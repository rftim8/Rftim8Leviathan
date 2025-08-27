cmake_minimum_required(VERSION 3.5.0)
project(_03122_MinimumNumberOfOperationsToSatisfyConditions VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_03122_MinimumNumberOfOperationsToSatisfyConditions main.cpp)

target_link_libraries(_03122_MinimumNumberOfOperationsToSatisfyConditions gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
