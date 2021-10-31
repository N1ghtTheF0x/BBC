cmake_minimum_required(VERSION 3.15) # Set the least required Version of CMake

set(CMAKE_CXX_STANDARD 17) # We're using c++17

set(BUILD_SHARED_LIBS OFF) # No DLL moving around

project(Skoge LANGUAGES CXX VERSION 1.0)

add_subdirectory(depend) # Compile needed libraries (SFML)
add_subdirectory(src) # Compile the project