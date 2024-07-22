# Add the executable for the project
file(GLOB SOURCES *.cpp *.c)

add_executable(OpenGL ${SOURCES})

# Link libraries
target_link_libraries(OpenGL glfw glad)


set_target_properties(OpenGL PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")
target_include_directories(OpenGL PRIVATE ${PROJECT_SOURCE_DIR}/include)
