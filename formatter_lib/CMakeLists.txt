cmake_minimum_required(VERSION 3.10)
project(formatter_lib)

add_library(formatter STATIC formatter.h formatter.cpp)

install(TARGETS formatter
        DESTINATION lib) 
install(FILES formatter.h
        DESTINATION include)
        
# target_compile_features(formatter PUBLIC cxx_std_17)
# target_compile_options(formatter PUBLIC -Wall -Wextra)
