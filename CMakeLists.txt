cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(main $SOURCE_FILES)
#set(SOURCE_FILES subclass_compile_test/library.cpp subclass_compile_test/library.h subclass_compile_test/base.cpp subclass_compile_test/base.h subclass_compile_test/sub.cpp subclass_compile_test/sub.h main.cpp)
#add_library(untitled SHARED ${SOURCE_FILES})
