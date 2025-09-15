#pragma once
#include <SDL3/SDL.h>
#include <string>
#include "../base.hpp"
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

  // 常用繪圖操作
  void clear(Color c);
  void fillRect(int x, int y, int w, int h, Color c);
  void drawLine(int x1, int y1, int x2, int y2, Color c);
  void drawCircle(int cx, int cy, int radius, Color c);
  void blit(Pixmap& src, int x, int y);

  // 存檔
  void saveBMP(const std::string& filename);
  // void savePNG(const std::string& filename); // 需要 SDL_image

  SDL_Surface* getSurface();

  SDL_Surface* surface;
  private:
};
