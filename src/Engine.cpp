#include "Engine.hpp"
#include "Camera.hpp"
#include "Shader.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

TimeManager timeManager;

WindowManager &Engine::getWindowManager() { return windowManager; }

Engine::Engine()
    : baseShader("/home/l/Programming/OpenGL/shaders/baseVertex.vert",
                 "/home/l/Programming/OpenGL/shaders/baseFragment.frag") {
  init();
}

void Engine::init() {
  glfwSetFramebufferSizeCallback(windowManager.getWindow(),
                                 framebuffer_size_callback);
  glfwSetCursorPosCallback(windowManager.getWindow(), mouse_callback);
  glfwSetScrollCallback(windowManager.getWindow(), scroll_callback);

  baseShader.use();
}

void Engine::update() {
  timeManager.updateTime();
  windowManager.update();
  processInput(windowManager.getWindow());
}

void Engine::render() {
  glm::mat4 model = glm::mat4(1.0f);
  baseShader.setMat4("model", model);
  glm::mat4 projection =
      glm::perspective(glm::radians(camera.Zoom),
                       (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
  baseShader.setMat4("projection", projection);
  // camera/view transformation
  glm::mat4 view = camera.GetViewMatrix();
  baseShader.setMat4("view", view);

  singleVoxelBuffer.draw();
}

// process all input: query GLFW whether relevant keys are pressed/released this
// frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    camera.ProcessKeyboard(FORWARD, timeManager.getDeltaTime());
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    camera.ProcessKeyboard(BACKWARD, timeManager.getDeltaTime());
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    camera.ProcessKeyboard(LEFT, timeManager.getDeltaTime());
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    camera.ProcessKeyboard(RIGHT, timeManager.getDeltaTime());

}

// glfw: whenever the window size changed (by OS or user resize) this callback
// function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width
  // and height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow *window, double xposIn, double yposIn) {
  float xpos = static_cast<float>(xposIn);
  float ypos = static_cast<float>(yposIn);

  if (firstMouse) {
    lastX = xpos;
    lastY = ypos;
    firstMouse = false;
  }

  float xoffset = xpos - lastX;
  float yoffset =
      lastY - ypos; // reversed since y-coordinates go from bottom to top

  lastX = xpos;
  lastY = ypos;

  camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
  camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
