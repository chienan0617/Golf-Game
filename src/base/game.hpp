#include "base.hpp"

class Game {
public:
  SDL_Event event;

  void run();
  void init();
  void loop();
  void dispose();
};
