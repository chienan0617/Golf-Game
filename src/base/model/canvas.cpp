#include "canvas.hpp"
#include "../state.hpp"

namespace Canvas {
  void renderClear() {
    SDL_RenderClear(State::renderer);
  }

  void renderPresent() {
    SDL_RenderPresent(State::renderer);
  }

  void setColor(Color c) {
    SDL_SetRenderDrawColor(State::renderer, c.r, c.g, c.b, c.a);
  }
}
