cmake_minimum_required(VERSION 3.21)
project(OO)

set(CMAKE_CXX_STANDARD 11)

add_executable(OO main.cpp IComparable.h IntWrapper.cpp IntWrapper.h StringWrapper.cpp StringWrapper.h sort.cpp sort.h)
