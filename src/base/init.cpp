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
    state.window = SDL_CreateWindow(title, w, h, 0);

    if (!state.window) {
      System::onError("error when create a window");
    }
  }

  void createRenderer() {
    state.renderer = SDL_CreateRenderer(state.window, nullptr);

    if (!state.renderer) {
      System::onError(SDL_GetError());
    }
  }

  void initDisplayMode() {
    state.primaryDisplayID = SDL_GetPrimaryDisplay();

    if (state.primaryDisplayID) {
      const SDL_DisplayMode* mode = SDL_GetDesktopDisplayMode(state.primaryDisplayID);

      if (mode) {
        *(state.primaryDisplayMode) = *mode;
      }
    }
    System::onError("could not handle init display mode");
  }
}
