cmake_minimum_required(VERSION 3.5)

project(HW_03_Guess_the_number CXX)

add_executable(guess_the_number
               guess_the_number.cpp

               check_value.cpp
               check_value.h
               menu.cpp
               menu.h
               random_value.cpp
               random_value.h
               record_table.cpp
               record_table.h
               systemfunc.cpp
               systemfunc.h

)

set_target_properties(guess_the_number
                      PROPERTIES CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON
)

target_compile_features(guess_the_number PUBLIC cxx_std_17)

if (MSVC)
  target_compile_options(guess_the_number PUBLIC /W4 /WX)
else()
  target_compile_options(guess_the_number PUBLIC -Wall -Wextra -Werror -pedantic)
endif()