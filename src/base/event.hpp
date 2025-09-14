#pragma once
#include "base.hpp"

namespace Event {
  // SDL_Event event;

  // void pollEvent();
  void detectQuit(SDL_Event &event);
  bool pollEvent(SDL_Event &event);
}
