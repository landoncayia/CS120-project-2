cmake_minimum_required(VERSION 3.15)
project(LC_Project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(LC_Project2
        main.cpp Library.h Library.cpp)

add_executable(LC_Project2_Testing
        testing.cpp Library.h Library.cpp)
