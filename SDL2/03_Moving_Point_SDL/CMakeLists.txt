cmake_minimum_required(VERSION 3.25)
project(MovingPoint)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++20")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Project files
add_executable(MovingPoint
        05_Sort_Counter.cpp
        )

target_link_libraries(
        ${PROJECT_NAME}
        ${SDL2_LIBRARIES}
)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES OUTPUT_NAME ../MovingPoint.app
)

