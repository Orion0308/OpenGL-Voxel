#include "WindowManager.hpp"

// Window
// Buffers
// Rendering
// Mechanics
// World
// Math

class Engine {
private:
  WindowManager windowManager;

public:
    WindowManager &getWindowManager();

    void init();
    void update();
    void render();
};
