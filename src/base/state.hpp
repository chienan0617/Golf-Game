#pragma once
#include "base.hpp"

namespace State {
  inline SDL_Window* window = nullptr;
  inline SDL_Renderer* renderer = nullptr;
  inline SDL_DisplayMode* primaryDisplayMode = nullptr;
  inline bool running = true;
  inline SDL_DisplayID primaryDisplayID;
}
