#include "Pixmap.hpp"
#include <stdexcept>
#include <cstring>  // for memset etc.

Pixmap::Pixmap(int width, int height, SDL_PixelFormat format) : surface(nullptr) {
  surface = SDL_CreateSurface(width, height, format);
  if (!surface) {
    throw std::runtime_error(std::string("Failed to create SDL Surface: ") + SDL_GetError());
  }
}

Pixmap::~Pixmap() {
  if (surface) {
    SDL_DestroySurface(surface);
    surface = nullptr;
  }
}

Pixmap::Pixmap(Pixmap&& other) noexcept : surface(other.surface) {
  other.surface = nullptr;
}

Pixmap& Pixmap::operator=(Pixmap&& other) noexcept {
  if (this != &other) {
    if (surface) {
      SDL_DestroySurface(surface);
    }
    surface = other.surface;
    other.surface = nullptr;
  }
  return *this;
}

int Pixmap::getWidth() const {
  return surface ? surface->w : 0;
}

int Pixmap::getHeight() const {
  return surface ? surface->h : 0;
}

SDL_PixelFormat Pixmap::getFormat() const {
  return surface ? surface->format : SDL_PIXELFORMAT_UNKNOWN;
}

void* Pixmap::getPixels() {
  return surface ? surface->pixels : nullptr;
}

int Pixmap::getPitch() const {
  return surface ? surface->pitch : 0;
}

void Pixmap::setPixel(int x, int y, Color c) {
  if (!surface) return;
  if (x < 0 || x >= surface->w || y < 0 || y >= surface->h) return;

  Uint32 color = SDL_MapSurfaceRGBA(surface, c.r, c.g, c.b, c.a);
  if (color == SDL_MapSurfaceRGBA(surface, 0, 0, 0, 0)) return;

  Uint32* pixels = static_cast<Uint32*>(surface->pixels);
  int pitch32 = surface->pitch / sizeof(Uint32);
  pixels[y * pitch32 + x] = color;
}

void Pixmap::getPixel(int x, int y, Color& c) const {
  c.r = c.g = c.b = c.a = 0;
  if (!surface) return;
  if (x < 0 || x >= surface->w || y < 0 || y >= surface->h) return;

  // 使用 SDL_ReadSurfacePixel 讀取單個像素的顏色
  if (SDL_ReadSurfacePixel(surface, x, y, &c.r, &c.g, &c.b, &c.a)) {
    // 處理錯誤
  }
}

SDL_Surface* Pixmap::getSurface() {
  return surface;
}
