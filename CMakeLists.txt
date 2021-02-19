cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(roman)

include(cmake/function.cmake)

add_subdirectory(convertor)
add_subdirectory(main)

add_subdirectory(gtest)
add_subdirectory(test)

