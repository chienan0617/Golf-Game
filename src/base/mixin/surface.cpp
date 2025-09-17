#include "surface.hpp"

Surface::Surface() {

}

Surface::Surface(int width, int height, SDL_PixelFormat format) {

}


Surface::~Surface() {
  if (surface) {
    SDL_DestroySurface(surface);
    surface = nullptr;
  }
}

bool Surface::initSurface(int width, int height, SDL_PixelFormat format) {
  surface = SDL_CreateSurface(width, height, format);
  return surface;
}

bool Surface::drawRect(Rect* rect, const Color c) {
  Uint32 color = SDL_MapSurfaceRGBA(surface, c.r, c.g, c.b, c.a);
  return SDL_FillSurfaceRect(surface, rect, color);
}
