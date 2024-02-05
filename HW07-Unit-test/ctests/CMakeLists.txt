
file(GLOB TEST_SRCS CONFIGURE_DEPENDS "*test*.cpp")

#  set(COMMON_SRCS
    #  "../src/myvector.hpp"
# )

foreach(test_src ${TEST_SRCS})
    get_filename_component(test_name ${test_src} NAME_WLE)
    add_executable(${test_name} ${test_src}
                                            ../vector_tests.cpp
                                            ../vector_tests.h
)
    target_include_directories(${test_name} PUBLIC ${CMAKE_SOURCE_DIR})
    add_test(NAME ${test_name}
             COMMAND ${test_name})
endforeach()
