#pragma once

#include <SDL3/SDL.h>
#include "Pixmap.hpp"

class Texture {
public:
  // 建構一個空的 texture（之後可能從 pixmap 更新／或作為目標 render target）
  Texture(SDL_Renderer* renderer, int width, int height, SDL_PixelFormat format, SDL_TextureAccess access);
  ~Texture();

  // 禁用複製
  Texture(const Texture&) = delete;
  Texture& operator=(const Texture&) = delete;

  // 可以移動
  Texture(Texture&& other) noexcept;
  Texture& operator=(Texture&& other) noexcept;

  int getWidth() const;
  int getHeight() const;

  // 從 Pixmap 創建 texture
  static Texture fromPixmap(SDL_Renderer* renderer, const Pixmap& pixmap);

  // 更新整張貼圖內容為 pixmap 的像素
  void updateFromPixmap(const Pixmap& pixmap);

  // 渲染貼圖
  // src 和 dst 可以選擇 nullptr 表示整張
  void render(SDL_Renderer* renderer, const SDL_FRect* dst, const SDL_FRect* src = nullptr);

  // 若需要把此 texture 當作 render target（offscreen render）
  void setAsRenderTarget(SDL_Renderer* renderer);
  static void resetRenderTarget(SDL_Renderer* renderer);

  SDL_Texture* texture;
};
