cmake_minimum_required(VERSION 3.10)
project(solver_lib)

add_library(solver_lib STATIC solver.h solver.cpp)

install(TARGETS solver_lib
        DESTINATION lib)
install(FILES solver.h
        DESTINATION include)
