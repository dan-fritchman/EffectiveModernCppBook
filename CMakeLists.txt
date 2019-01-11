cmake_minimum_required(VERSION 3.8)
project(cpp_tutorials)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp enum.h print.h other.h deleted.h override.h init.h templates.h locks.h nullptr.h auto_decl.h const_thread.h move.h smart_ptr.h pimpl/impl.cpp pimpl/pimpl.h pimpl/tests.h)
add_executable(main ${SOURCE_FILES})

#set(TEST_SOURCE_FILES docker/test.cpp)
#add_executable(test_docker ${TEST_SOURCE_FILES})

