cmake_minimum_required(VERSION 3.17)
project(tpa2020_shapeDisplay)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

add_executable(tpa2020_shapeDisplay main.cpp
        src/display.cpp
        src/point.cpp
        src/shape.cpp
        )