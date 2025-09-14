#pragma once
#include <SDL3/SDL.h>
#include "../base.hpp"
#include <string>
#include "../format/color.hpp"

class Pixmap {
public:
  Pixmap(int width, int height, SDL_PixelFormat format = SDL_PIXELFORMAT_RGBA8888);
  ~Pixmap();

  // 禁用複製
  Pixmap(const Pixmap&) = delete;
  Pixmap& operator=(const Pixmap&) = delete;

  // 可以移動
  Pixmap(Pixmap&& other) noexcept;
  Pixmap& operator=(Pixmap&& other) noexcept;

  int getWidth() const;
  int getHeight() const;
  SDL_PixelFormat getFormat() const;

  // 取得像素緩衝（指標），pitch 是每行 byte 數
  void* getPixels();
  int getPitch() const;

  // 設一個像素 (x,y)，值為 r,g,b,a
  void setPixel(int x, int y, Color c);
  // 取一個像素
  void getPixel(int x, int y, Color& c) const;

  SDL_Surface *getSurface();

  SDL_Surface* surface;
};
