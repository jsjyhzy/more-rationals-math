project(MoreRationalsMath CXX)
cmake_minimum_required(VERSION 3.22)

add_subdirectory(more_rationals_math)

enable_testing()
add_subdirectory(tests)