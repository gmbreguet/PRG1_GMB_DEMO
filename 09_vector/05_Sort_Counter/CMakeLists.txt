cmake_minimum_required(VERSION 3.25)
project(05_Sort_Counter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++20")

# Project files
add_executable(05_Sort_Counter
        05_Sort_Counter.cpp
        )

target_link_libraries(
        ${PROJECT_NAME}
)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES OUTPUT_NAME ../SortCounter.app
)

