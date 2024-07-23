#include "WindowManager.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>

WindowManager::WindowManager() {
  height = 800;
  width = 1000;
  title = "OpenGL";
  if (!glfwInit()) {
    throw std::runtime_error("Failed To Init GLFW (WindowManager.hpp)");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  window = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (!window) {
    throw std::runtime_error("Window Creation Failed (WindowManager.hpp");
    glfwTerminate();
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    glfwDestroyWindow(window);
    glfwTerminate();
    throw std::runtime_error("Failed to initialize GLAD (WindowManager.cpp)");
  }
  glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
  glViewport(0, 0, width, height);

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  glEnable(GL_DEPTH_TEST);

  // Enable face culling
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK); // Cull the back faces (default)
  glFrontFace(GL_CW);  // Define the front face (default is counter-clockwise)
  glfwMakeContextCurrent(window);
}

WindowManager::~WindowManager() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

GLFWwindow *WindowManager::getWindow() { return window; }

void WindowManager::update_clearWindow() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void WindowManager::update_processInput() {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

void WindowManager::update() {
  update_clearWindow();
  update_processInput();
  toggleWireframe();
}
