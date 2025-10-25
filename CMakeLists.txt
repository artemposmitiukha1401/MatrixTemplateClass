cmake_minimum_required(VERSION 4.0)
project(matrix_template_class)

set(CMAKE_CXX_STANDARD 20)

add_executable(matrix_template_class main.cpp
        Matrix.h
        Point.h
        Point.cpp)
