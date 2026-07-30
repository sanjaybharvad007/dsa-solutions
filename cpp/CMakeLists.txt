cmake_minimum_required(VERSION 3.16)
project(dsa_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -O2)

enable_testing()
add_executable(test_solutions tests/test_solutions.cpp)
target_include_directories(test_solutions PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
add_test(NAME solutions COMMAND test_solutions)
