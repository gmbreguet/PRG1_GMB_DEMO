cmake_minimum_required(VERSION 3.25)
project(07_amities_fct_independante_amie_de_plusieurs_classes)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++20")

include_directories(.)

add_executable(07_amities_fct_independante_amie_de_plusieurs_classes
        c1.cpp
        c1.hpp
        c2.cpp
        c2.hpp
        main.cpp)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES OUTPUT_NAME ../Amitie.app
)