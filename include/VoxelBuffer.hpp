#pragma once
#include "VoxelData.hpp"
#include <glad/glad.h>

class SingleVoxelBuffer {
private:
  Voxel voxelData;
  unsigned int VBO{0}, VAO{0};

  void initiliseSingleVoxelBuffer() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(voxelData.getVertices()),
                 voxelData.getVertices().data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                          (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                          (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
  }

public:
  SingleVoxelBuffer() { initiliseSingleVoxelBuffer(); }
  unsigned int &getVAO() { return VAO; }
  unsigned int &getVBO() { return VBO; }

  void draw() {
    // Bind the VAO
    glBindVertexArray(VAO);

    // Draw the cube
    glDrawArrays(GL_TRIANGLES, 0,
                 36); // Assuming you are using 36 vertices for the cube

    // Unbind the VAO
    glBindVertexArray(0);
  }
};
