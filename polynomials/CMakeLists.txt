cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(polynomials)

include(cmake/function.cmake)

add_subdirectory(polynomials)
add_subdirectory(main)

add_subdirectory(gtest)
add_subdirectory(test)

