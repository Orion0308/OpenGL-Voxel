# Add the executable for the project
file(GLOB SOURCES *.cpp)

add_executable(OpenGL ${SOURCES})

# Link libraries
target_link_libraries(OpenGL ${PROJECT_LINK_LIBS})


set_target_properties(OpenGL PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")
