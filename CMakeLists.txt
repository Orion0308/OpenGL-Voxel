cmake_minimum_required(VERSION 3.29)
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
add_subdirectory(include)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)
