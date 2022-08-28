cmake_minimum_required(VERSION 3.23)
project(rnlib)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_library(rnlib
        src/rn.cpp
        src/rn.h)
