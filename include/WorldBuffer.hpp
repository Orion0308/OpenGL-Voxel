#pragma once

#include "Shader.hpp"
#include "VoxelBuffer.hpp"
#include <glm/glm.hpp>
#include <memory>
#include <vector>

class WorldBuffer {
private:
  std::vector<glm::vec3> positions{0};
  unsigned int VAO{0}, VBO{0}, instanceVBO{0};
  std::unique_ptr<Voxel> voxelData;

public:
  WorldBuffer() {
    voxelData = std::make_unique<Voxel>();
    generateWorldBuffer();
  }

  std::vector<glm::vec3> &getPositions() { return positions; }

  void initilisePositions() {
    for (float x = 0.0f; x < 16; x++) {
      for (float y = 0.0f; y > -16; y--) {
        for (float z = 0.0f; z < 16; z++) {

          glm::vec3 pos{x, y, z};
          positions.push_back(pos);
        }
      }
    }
  }

  void generateWorldBuffer() {
    initilisePositions();

    glGenBuffers(1, &instanceVBO);
    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * positions.size(),
                 positions.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,
                 voxelData->getVertices().size() * sizeof(float),
                 voxelData->getVertices().data(), GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                          (void *)(3 * sizeof(float)));

    glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glVertexAttribDivisor(2, 1);
  }

  void draw() {
    glBindVertexArray(VAO);

    glDrawArraysInstanced(GL_TRIANGLES, 0, 36, positions.size());

    glBindVertexArray(0);
  }
};
