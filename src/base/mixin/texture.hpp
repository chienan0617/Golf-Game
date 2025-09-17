#pragma once
#include "../base.hpp"
#include "surface.hpp"
#include <optional>  // if needed

class Texture {
public:
  SDL_Texture* texture = nullptr;
  SDL_FRect* renderDst = nullptr;

  Texture();
  // existing pointer-one
  Texture(Surface* surface);

  // new overloads:
  Texture(Surface& surface);
  Texture(const Surface& surface);

  // optionally: one that takes std::optional<Surface>
  Texture(const std::optional<Surface>& surfOpt);
  Texture(const std::optional<Surface*> surfOpt);

  ~Texture();

  bool renderTexture();
  bool initTexture();
};
