cmake_minimum_required(VERSION 3.5.0)
project(_00690_EmployeeImportance VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_00690_EmployeeImportance main.cpp)

target_link_libraries(_00690_EmployeeImportance gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
