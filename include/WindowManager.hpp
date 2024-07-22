#include "glad/glad.h"
#include <GLFW/glfw3.h>

class WindowManager {
private:
  int height, width;
  const char *title;
  GLFWwindow *window;

public:
  WindowManager();
  ~WindowManager();

  GLFWwindow *getWindow();

  void update();

  //Update members
  void update_clearWindow();
  void update_processInput();

};
