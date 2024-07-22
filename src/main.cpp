#include "Engine.hpp"
#include <GL/gl.h>
#include <GLFW/glfw3.h>

int main() {
  Engine engine;
  auto *window = engine.getWindowManager().getWindow();

  while (!glfwWindowShouldClose(window)) {
    engine.update();

    // render loop starts here
    engine.render();

    glfwPollEvents();
    glfwSwapBuffers(window);
  }
  return 0;
}
