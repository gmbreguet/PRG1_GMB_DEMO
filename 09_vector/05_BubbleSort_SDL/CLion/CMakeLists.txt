# https://trenki2.github.io/blog/2017/06/02/using-sdl2-with-cmake/
cmake_minimum_required(VERSION 3.25)
project(05_BubbleSort_SDL_CLion)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++20")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Project files
add_executable(05_BubbleSort_SDL_CLion
        05_BubbleSort_SDL_CLion.cpp
        )

target_link_libraries(
        ${PROJECT_NAME}
        ${SDL2_LIBRARIES}
)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES OUTPUT_NAME ../BubbleSort.app
        )