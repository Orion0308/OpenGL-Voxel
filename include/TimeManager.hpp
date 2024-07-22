#pragma once

#include <GLFW/glfw3.h>

class TimeManager {
private:
  float deltaTime{0.0f};
  float lastFrame{0.0f};

public:
  float getDeltaTime() { return deltaTime; }
  float getLastFrame() { return lastFrame; }

  void updateTime() {
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
  }
};
