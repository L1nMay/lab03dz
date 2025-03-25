cmake_minimum_required(VERSION 3.10)
project(formatter_ex)

add_library(formatter_ex STATIC formatter_ex.h formatter_ex.cpp)

# include_directories(${CMAKE_SOURCE_DIR}/../formatter_lib)
target_link_libraries(formatter_ex PRIVATE formatter) 

install(TARGETS formatter_ex
        DESTINATION lib)
install(FILES formatter_ex.h
        DESTINATION include)

# target_compile_features(formatter_ex PUBLIC cxx_std_17)
# target_compile_options(formatter_ex PUBLIC -Wall -Wextra)
