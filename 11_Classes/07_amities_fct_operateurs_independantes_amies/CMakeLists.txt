cmake_minimum_required(VERSION 3.25)
project(07_amities_fct_operateurs_independantes_amies)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++20")

include_directories(.)

add_executable(07_amities_fct_operateurs_independantes_amies
        main.cpp
        vecteur.cpp
        vecteur.hpp)

set_target_properties(
        ${PROJECT_NAME}
        PROPERTIES OUTPUT_NAME ../Amitie.app
)