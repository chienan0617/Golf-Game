#pragma once
#include "../mixin/surface.hpp"
#include "../mixin/texture.hpp"
#include "sized_component.hpp"
#include <optional>

class DrawableComponent : public SizedComponent {
public:
  std::optional<Surface*> surface;
  std::optional<Texture*> texture;
  DrawableComponent(const char* name);

  void initPixmap(int width, int height);
  void initPixmap();
  // void initTexture(int width, int height, SDL_PixelFormat format = SDL_PIXELFORMAT_RGBA32, SDL_TextureAccess access = SDL_TEXTUREACCESS_STATIC);
  void initTexture();
};
