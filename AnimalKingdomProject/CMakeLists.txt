cmake_minimum_required(VERSION 3.10) # Sets the minimum CMake version required to process this file.
project(AnimalKingdom) # names the proj (Can be used for vars, folders, idk)

set(CMAKE_CXX_STANDARD 17) # compile C++17 std

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

add_executable(AnimalKingdomMain main.cpp) # Creates an executable named "AnimalKingdomMain" using main.cpp 
# "make" cmd CMake will produece binary with that name