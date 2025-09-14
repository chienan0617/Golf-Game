#include "base.hpp"
#include "game.hpp"
#include "init.hpp"
#include "state.hpp"
#include "system.hpp"
#include "event.hpp"
#include "object/object_manager.hpp"
#include "model/canvas.hpp"

void Game::run() {
  Game::init();
  Game::loop();
  Game::dispose();
}

void Game::init() {
  Init::initSDL();
  Init::createWindow("Test", 640, 480);
  Init::createRenderer();
  // Init::initDisplayMode(); // ! fatal function!!!
  ObjectManager::onCreate();
}

void Game::loop() {
  while (State::running) {
    while(Event::pollEvent(event)) {
      Event::detectQuit(event);
    }

    Canvas::renderClear();
    ObjectManager::onUpdate();
    ObjectManager::onRender();
    Canvas::renderPresent();

    System::delay(8);
  }
}

void Game::dispose() {
  System::destroyWindow();
  System::destroyRenderer();
  System::quit();
}
