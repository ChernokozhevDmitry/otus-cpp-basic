cmake_minimum_required(VERSION 3.5)

project(topk_words CXX)
project(topk_words_mythread CXX)

add_executable(topk_words topk_words.cpp)
add_executable(topk_words_mythread topk_words_mythread.cpp)

set_target_properties(topk_words PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
set_target_properties(topk_words_mythread PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

if (MSVC)
  target_compile_options(topk_words PUBLIC /W3 /WX)
  target_compile_options(topk_words_mythread PUBLIC /W3 /WX)
else()
  target_compile_options(topk_words PUBLIC -Wall -Wextra -Werror -pedantic)
  target_compile_options(topk_words_mythread PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
