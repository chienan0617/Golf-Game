#pragma once
#include "base.hpp"

namespace Init {
  void initSDL();
  void SDLCALL createWindow(const char* title, int w, int h);
  void SDLCALL createRenderer();
  void initDisplayMode();
};
