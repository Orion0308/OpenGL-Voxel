#pragma once

#include <memory>

#include "WorldBuffer.hpp"

class WorldManager {
private:
  std::unique_ptr<WorldBuffer> worldBuffer;

public:
    WorldManager(); //make_unique worldBuffer
};
