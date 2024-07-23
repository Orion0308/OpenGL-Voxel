#pragma once

#include "Shader.hpp"
#include "stb_image.h"
#include <glad/glad.h>
#include <iostream>

class Texture {
private:
  Shader &shad;
  unsigned int texture;

  void initTexture() {
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                    GL_REPEAT); // set texture wrapping to GL_REPEAT (default
                                // wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int w, h, nrChan;
    unsigned char *data =
        stbi_load("/home/l/Programming/OpenGL/textures/oak_planks.png", &w, &h,
                  &nrChan, 0);
    if (data) {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE,
                   data);
      glGenerateMipmap(GL_TEXTURE_2D);
      // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
      //                 GL_LINEAR_MIPMAP_LINEAR);
      // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
      std::cout << "Texture loaded successfully. Size: " << w << "x" << h
                << ", Channels: " << nrChan << std::endl;
    } else {
      std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    shad.use();
    shad.setInt("texture", 0);
  }

public:
  Texture(Shader &shad) : shad(shad) { initTexture(); }
  unsigned int &getTexture() { return texture; }
};
