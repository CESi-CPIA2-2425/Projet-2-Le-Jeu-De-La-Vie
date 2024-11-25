cmake_minimum_required(VERSION 3.29)
project(Prosit_2_4_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Prosit_2_4_code
    main.cpp
    Parcours.cpp
    Parcours.h
    Parcours3D.cpp
    Parcours3D.h
    Point.cpp
    Point.h
    Point3D.cpp
    Point3D.h)
