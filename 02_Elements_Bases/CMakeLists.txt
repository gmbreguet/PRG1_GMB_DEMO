cmake_minimum_required(VERSION 3.25)
project(02_Elements_Bases)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic")

add_executable(02_Elements_Bases
#        02_01_char.cpp
#        02_02_bool.cpp
#        02_03_string_concat.cpp
         03_01_spaceship.cpp
        )
