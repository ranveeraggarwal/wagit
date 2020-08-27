cmake_minimum_required(VERSION 3.17)
project(wagit)

set(CMAKE_CXX_STANDARD 20)

add_executable(wagit main.cpp sources/wagit.cpp headers/wagit.h)

find_package(argh)
target_link_libraries(wagit argh)