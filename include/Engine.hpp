#include "Interfaces/ShaderTextureInterface.hpp"
#include "Shader.hpp"
#include "Texture.hpp"
#include "VoxelBuffer.hpp"
#include "WindowManager.hpp"
#include "WorldBuffer.hpp"

// Window //
// Buffers
// Rendering
// Mechanics
// World
// Math

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

class Engine {
private:
  WindowManager windowManager;
  SingleVoxelBuffer singleVoxelBuffer;
  Shader baseShader;
  Texture texture;
  IShaderTexture iShaderTexture;
  WorldBuffer worldBuffer;


public:
  Engine();

  WindowManager &getWindowManager();

  void init();
  void update();
  void render();
};
