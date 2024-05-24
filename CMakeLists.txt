cmake_minimum_required(VERSION 3.27)
project(contest5)

set(CMAKE_CXX_STANDARD 17)

add_executable(contest5 main.cpp
        src/IShape.cpp
        IShape.h
        src/vector.cpp
        vector.h
        src/point.cpp
        point.h
        src/segment.cpp
        segment.h
        src/line.cpp
        line.h
)
