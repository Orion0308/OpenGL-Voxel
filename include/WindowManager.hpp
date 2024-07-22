#include "glad/glad.h"
#include <GLFW/glfw3.h>

class WindowManager {
private:
  int height, width;
  const char *title;
  GLFWwindow *window;
  bool wireframe = false;

public:
  WindowManager();
  ~WindowManager();

  GLFWwindow *getWindow();

  void toggleWireframe() {
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
      wireframe = !wireframe;
    if (wireframe) {
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Set to wireframe mode
    } else {
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Set to normal mode
    }
  }

  void update();

  // Update members
  void update_clearWindow();
  void update_processInput();
};
