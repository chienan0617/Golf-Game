#include "canvas.hpp"
#include "../state.hpp"

namespace Canvas {
  void renderClear() {
    SDL_RenderClear(state.renderer);
  }

  void renderPresent() {
    SDL_RenderPresent(state.renderer);
  }

  void setColor(Color c) {
    SDL_SetRenderDrawColor(state.renderer, c.r, c.g, c.b, c.a);
  }
}
