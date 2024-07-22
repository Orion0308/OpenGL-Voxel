#include "Engine.hpp"

WindowManager &Engine::getWindowManager() { return windowManager; }

Engine::Engine() { init(); }

void Engine::init() {}

void Engine::update() { windowManager.update(); }

void Engine::render() {}
