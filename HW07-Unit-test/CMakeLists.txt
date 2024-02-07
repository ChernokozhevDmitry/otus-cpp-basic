cmake_minimum_required(VERSION 3.5)

project(testing CXX)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED TRUE)

# add_executable(containers_tests main.cpp
#                                 vector_tests.cpp
#                                 vector_tests.h
#                                 # singlylinkedlist_tests.cpp
#                                 # doublylinkedlist_tests.cpp
# )

# set_target_properties(containers_tests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

# if (MSVC)
#   target_compile_options(containers_tests PUBLIC /W4 /WX)
# else()
#   target_compile_options(containers_tests PUBLIC -Wall -Wextra -Werror -pedantic)
# endif()

# add_subdirectory(ctests)

# enable_testing()

add_subdirectory(gtests)

# add_subdirectory(healthchecker)
