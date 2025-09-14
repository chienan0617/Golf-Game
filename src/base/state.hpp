#pragma once
#include "base.hpp"

struct State {
  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
  SDL_DisplayMode* primaryDisplayMode = nullptr;
  bool running = true;
  SDL_DisplayID primaryDisplayID;
};

inline State state;
