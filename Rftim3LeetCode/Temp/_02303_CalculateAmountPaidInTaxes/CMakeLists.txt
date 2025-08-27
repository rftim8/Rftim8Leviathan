cmake_minimum_required(VERSION 3.5.0)
project(_02303_CalculateAmountPaidInTaxes VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(/usr/src/gtest/ gtest)

add_executable(_02303_CalculateAmountPaidInTaxes main.cpp)

target_link_libraries(_02303_CalculateAmountPaidInTaxes gtest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
