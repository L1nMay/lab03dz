cmake_minimum_required(VERSION 3.10)
project(solver)

add_executable(solver main.cpp)

# include_directories(${CMAKE_SOURCE_DIR}/../formatter_ex)
# include_directories(${CMAKE_SOURCE_DIR}/../solver_lib)
target_link_libraries(solver PRIVATE formatter_ex solver_lib)

# target_compile_features(solver PRIVATE cxx_std_17)
# target_compile_options(solver PRIVATE -Wall -Wextra)
