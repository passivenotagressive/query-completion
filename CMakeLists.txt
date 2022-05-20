cmake_minimum_required(VERSION 3.21)
project(auto-addition)

set(CMAKE_CXX_STANDARD 20)
include_directories("lib" "lib/my_test")
set(SRC_LIST
        source/parser.cpp lib/parser/parser.h
        source/suggestion.cpp lib/suggestion/suggestion.h
        lib/correcter/correcter.h source/correcter.cpp
        suggest/suggest.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
