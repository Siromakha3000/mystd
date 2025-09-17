cmake_minimum_required(VERSION 3.30)
project(mystd)

set(CMAKE_CXX_STANDARD 20)

add_library(mystd STATIC library.cpp library.h
        src/Array.h
        src/LinkedList.h
        src/Collection.h
        src/Matrix.h)

add_executable(mystd_test test/mystd_test.cpp
        test/linked_list_test.cpp
        test/test_utils.h
        test/array_test.cpp
        test/matrix_test.cpp)

target_link_libraries(mystd_test PRIVATE mystd)