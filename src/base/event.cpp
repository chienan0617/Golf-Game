#include "event.hpp"
#include "state.hpp"

namespace Event {
  void detectQuit(SDL_Event &event) {
    if (event.type == SDL_EVENT_QUIT) {
      State::running = false;
    }
  }

  bool pollEvent(SDL_Event &event) {
    return SDL_PollEvent(&event);
  }
}
