cmake_minimum_required(VERSION 3.29)
project(AOC25)

set(CMAKE_CXX_STANDARD 26)

add_executable(AOC25 main.cpp
        Day01.h)

set(INPUT_FOLDER "puzzle_inputs")

add_custom_target(copy_inputs ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/${INPUT_FOLDER}"
        "${CMAKE_CURRENT_BINARY_DIR}/${INPUT_FOLDER}"
        COMMENT "Copying puzzle_inputs to binary directory..."
)

add_dependencies(AOC25 copy_inputs)