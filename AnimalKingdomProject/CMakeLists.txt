cmake_minimum_required(VERSION 3.10) # Sets the minimum CMake version required to process this file.
project(AnimalKingdom) # names the proj (Can be used for vars, folders, idk)

set(CMAKE_CXX_STANDARD 17) # compile C++17 std

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Put runtime binaries under the build directory (build/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# ${CMAKE_BINARY_DIR} is your build folder (the one created by build.sh).
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) makes executables land in build/bin instead of the source tree or configuration-specific folders.

add_executable(AnimalKingdomMain main.cpp) # Creates an executable named "AnimalKingdomMain" using main.cpp 
# "make" cmd CMake will produece binary with that name