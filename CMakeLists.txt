cmake_minimum_required(VERSION 3.21)
project(cmake_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(cmake_test
        tester.cpp aboba.cpp aboba.h)
