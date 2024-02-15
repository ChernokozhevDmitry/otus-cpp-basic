cmake_minimum_required(VERSION 3.5)

project(testing CXX)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED TRUE)

enable_testing()

add_subdirectory(gtests)
