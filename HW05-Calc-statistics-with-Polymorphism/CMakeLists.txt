cmake_minimum_required(VERSION 3.5)

project(HW05-Calc-statistics-with-Polymorphism CXX)

add_executable(statistics statistics.cpp)

set_target_properties(statistics PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
  target_compile_options(statistics PUBLIC /W4 /WX)
else()
  target_compile_options(statistics PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
