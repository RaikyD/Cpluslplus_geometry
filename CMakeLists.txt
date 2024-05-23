cmake_minimum_required(VERSION 3.27)
project(contest5)

set(CMAKE_CXX_STANDARD 17)

add_executable(contest5 main.cpp
        IShape.cpp
        IShape.h
        Vector.cpp
        Vector.h
        Point.cpp
        Point.h
        Segment.cpp
        Segment.h
        Line.cpp
        Line.h
)
