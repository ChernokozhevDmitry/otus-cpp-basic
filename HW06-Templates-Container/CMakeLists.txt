cmake_minimum_required(VERSION 3.5)

project(containers CXX)

add_executable(containers containers.cpp
                          myvector.hpp
                          # mylist.hpp
)

set_target_properties(containers PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
  target_compile_options(containers PUBLIC /W4 /WX)
else()
  target_compile_options(containers PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
