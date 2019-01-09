cmake_minimum_required(VERSION 3.8)
project(cpp_tutorials)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp enum.h print.h other.h deleted.h override.h templates.h)
add_executable(main ${SOURCE_FILES})

#set(TEST_SOURCE_FILES docker/test.cpp)
#add_executable(test_docker ${TEST_SOURCE_FILES})

