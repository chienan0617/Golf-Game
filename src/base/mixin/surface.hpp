#pragma once
#include "../base.hpp"
// #include ""

class Surface {
public:
  SDL_Surface* surface = nullptr;

  Surface(int width, int height, SDL_PixelFormat format = SDL_PIXELFORMAT_RGBA32);
  Surface();
  ~Surface();

  bool initSurface(int width, int height, SDL_PixelFormat format = SDL_PIXELFORMAT_RGBA32);
  bool drawRect(Rect* rect, Color color);

  SDL_PixelFormat getFormat() const;
};
