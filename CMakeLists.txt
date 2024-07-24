cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 23)


# Set the project name and version
project(OpenGL VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -Wall -Wextra -Wpedantic")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# Add subdirectories
add_subdirectory(src)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)


find_package(glfw3 3.3 REQUIRED)

add_library(glad STATIC src/glad.c)
target_include_directories(glad PUBLIC include)
target_compile_options(glad PRIVATE -Wno-old-style-cast -Wno-c++11-narrowing -Wno-iso-c++-forbidden-cast)
