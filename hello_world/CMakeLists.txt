cmake_minimum_required(VERSION 3.10)
project(hello_world)

add_executable(hello_world main.cpp)

# include_directories(${CMAKE_SOURCE_DIR}/../formatter_ex)
target_link_libraries(hello_world PRIVATE formatter_ex)

# target_compile_features(hello_world PRIVATE cxx_std_17)
# target_compile_options(hello_world PRIVATE -Wall -Wextra)
