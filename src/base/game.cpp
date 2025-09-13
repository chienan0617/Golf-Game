#include "game.hpp"
#include "init.hpp"
#include "state.hpp"

class Game {
public:
  void run() {
    init();
  }

  void init() {
    Init::initSDL();
    Init::createWindow("Test", 640, 480);
    Init::createRenderer();
  }

  void loop() {
    while (State::running) {

    }
  }
};
