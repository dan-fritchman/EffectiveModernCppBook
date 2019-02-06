cmake_minimum_required(VERSION 3.4)
project(cpp_tutorials)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/tutorials/main.cpp src/tutorials/enum.h src/tutorials/print.h src/tutorials/other.h src/tutorials/deleted.h src/tutorials/override.h src/tutorials/init.h src/tutorials/templates.h src/tutorials/locks.h src/tutorials/nullptr.h src/tutorials/auto_decl.h src/tutorials/const_thread.h src/tutorials/move.h src/tutorials/smart_ptr.h src/tutorials/pimpl/impl.cpp src/tutorials/pimpl/pimpl.h src/tutorials/pimpl/tests.h src/tutorials/lambda.h src/tutorials/concurrency.h src/tutorials/tweaks.h)
add_executable(main ${SOURCE_FILES})

#set(TEST_SOURCE_FILES docker/test.cpp)
#add_executable(test_docker ${TEST_SOURCE_FILES})

