#include "base.hpp"
#include "game.hpp"
#include "init.hpp"
#include "state.hpp"
#include "system.hpp"
#include "event.hpp"

void Game::run() {
  Game::init();
  Game::loop();
  Game::dispose();
}

void Game::init() {
  Init::initSDL();
  Init::createWindow("Test", 640, 480);
  Init::createRenderer();
}

void Game::loop() {
  while (State::running) {
    while(Event::pollEvent(event)) {
      Event::detectQuit(event);
    }
  }
}

void Game::dispose() {
  System::destroyWindow();
  System::destroyRenderer();
  System::quit();
}
