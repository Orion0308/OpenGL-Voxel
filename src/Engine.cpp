#include "Engine.hpp"

WindowManager &Engine::getWindowManager() { return windowManager; }

void Engine::init() {}

void Engine::update() { windowManager.update(); }

void Engine::render() {}
