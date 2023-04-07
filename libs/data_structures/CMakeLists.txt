cmake_minimum_required(VERSION 3.22)
project(Project C)

set(CMAKE_C_STANDARD 99)

add_executable(Project ../../main.c vector/vector.c)

add_library(data_structures
        vector/vector.c
        vector/vector.h)