cmake_minimum_required(VERSION 3.22)
project(Algorithm C)

set(CMAKE_C_STANDARD 23)

add_library(Algorithm arrlst.c linklst.c)

set(Sources main.c arrlst.c linklst.c)
set(Headers collections.h)
add_executable(Main ${Sources} ${Headers})
