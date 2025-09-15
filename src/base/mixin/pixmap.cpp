#include "Pixmap.hpp"
#include <stdexcept>
#include <cstring>  // for memset

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
  Uint32* pixels = static_cast<Uint32*>(surface->pixels);
  int pitch32 = surface->pitch / sizeof(Uint32);
  pixels[y * pitch32 + x] = color;
}

void Pixmap::getPixel(int x, int y, Color& c) const {
  c.r = c.g = c.b = c.a = 0;
  if (!surface) return;
  if (x < 0 || x >= surface->w || y < 0 || y >= surface->h) return;

  SDL_ReadSurfacePixel(surface, x, y, &c.r, &c.g, &c.b, &c.a);
}

void Pixmap::clear(Color c) {
  if (!surface) return;
  Uint32 color = SDL_MapSurfaceRGBA(surface, c.r, c.g, c.b, c.a);
  SDL_FillSurfaceRect(surface, nullptr, color);
}

void Pixmap::fillRect(int x, int y, int w, int h, Color c) {
  if (!surface) return;
  SDL_Rect rect { x, y, w, h };
  Uint32 color = SDL_MapSurfaceRGBA(surface, c.r, c.g, c.b, c.a);
  SDL_FillSurfaceRect(surface, &rect, color);
}

void Pixmap::drawLine(int x1, int y1, int x2, int y2, Color c) {
  if (!surface) return;
  int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
  int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
  int err = dx + dy, e2;

  while (true) {
    setPixel(x1, y1, c);
    if (x1 == x2 && y1 == y2) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x1 += sx; }
    if (e2 <= dx) { err += dx; y1 += sy; }
  }
}

void Pixmap::drawCircle(int cx, int cy, int radius, Color c) {
  if (!surface) return;
  int x = radius, y = 0;
  int err = 0;

  while (x >= y) {
    setPixel(cx + x, cy + y, c);
    setPixel(cx + y, cy + x, c);
    setPixel(cx - y, cy + x, c);
    setPixel(cx - x, cy + y, c);
    setPixel(cx - x, cy - y, c);
    setPixel(cx - y, cy - x, c);
    setPixel(cx + y, cy - x, c);
    setPixel(cx + x, cy - y, c);

    y += 1;
    if (err <= 0) {
      err += 2*y + 1;
    } else {
      x -= 1;
      err -= 2*x + 1;
    }
  }
}

void Pixmap::blit(Pixmap& src, int x, int y) {
  if (!surface || !src.surface) return;
  SDL_Rect dstRect { x, y, src.getWidth(), src.getHeight() };
  SDL_BlitSurface(src.surface, nullptr, surface, &dstRect);
}

void Pixmap::saveBMP(const std::string& filename) {
  if (!surface) return;
  SDL_SaveBMP(surface, filename.c_str());
}

// void Pixmap::savePNG(const std::string& filename) {
//   if (!surface) return;
//   if (IMG_SavePNG(surface, filename.c_str()) != 0) {
//     throw std::runtime_error(std::string("Failed to save PNG: ") + SDL_GetError());
//   }
// }

SDL_Surface* Pixmap::getSurface() {
  return surface;
}
