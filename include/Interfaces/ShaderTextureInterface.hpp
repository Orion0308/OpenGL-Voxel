#pragma once

#include "Shader.hpp"
#include "Texture.hpp"

class IShaderTexture {
public:
  IShaderTexture(Shader &shader, Texture &texture)
      : shader(shader), texture(texture) {}
  void sendTextureToShader() {
    shader.use();
    shader.setInt("texture", 0);
  }

private:
  Shader &shader;
  Texture &texture;
};
