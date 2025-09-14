#include "init.hpp"
#include "state.hpp"
#include "system.hpp"
#include <stdio.h>

namespace Init {
  void initSDL() {
    bool state = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    if (!state) {
      System::onError("SDL_Init Error:");
    }
  }

  void createWindow(const char* title, int w, int h) {
    State::window = SDL_CreateWindow(title, w, h, 0);

    if (!State::window) {
      System::onError("error when create a window");
    }
  }

  void createRenderer() {
    State::renderer = SDL_CreateRenderer(State::window, nullptr);

    if (!State::renderer) {
      System::onError(SDL_GetError());
    }
  }

  void initDisplayMode() {
    State::primaryDisplayID = SDL_GetPrimaryDisplay();

    if (State::primaryDisplayID) {
      const SDL_DisplayMode* mode = SDL_GetDesktopDisplayMode(State::primaryDisplayID);

      if (mode) {
        *(State::primaryDisplayMode) = *mode;
      }
    }
    System::onError("Haaaaaaaa");
  }
}
