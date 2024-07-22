

#include <array>
#include <glm/glm.hpp>

class Voxel {
private:
  std::array<float,180> vertices = {
      // Back face
      -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // Bottom-left
       0.5f, -0.5f, -0.5f,  1.0f, 0.0f, // bottom-right
       0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
       0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
      -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
      -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, // bottom-left
      // Front face
      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
       0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
       0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
       0.5f,  0.5f,  0.5f,  1.0f, 1.0f, // top-right
      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
      -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, // top-left
      // Left face
      -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
      -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-left
      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-left
      -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-right
      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
      // Right face
       0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
       0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
       0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
       0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // bottom-right
       0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
       0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // top-left
      // Bottom face
      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
       0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
       0.5f, -0.5f, -0.5f,  1.0f, 1.0f, // top-left
       0.5f, -0.5f,  0.5f,  1.0f, 0.0f, // bottom-left
      -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, // top-right
      -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, // bottom-right
      // Top face
      -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, // top-left
       0.5f,  0.5f, -0.5f,  1.0f, 1.0f, // top-right
       0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
       0.5f,  0.5f,  0.5f,  1.0f, 0.0f, // bottom-right
      -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, // bottom-left
      -0.5f,  0.5f, -0.5f,  0.0f, 1.0f  // top-left
  };

public:
   std::array<float, 180> &getVertices() { return vertices; }
};
