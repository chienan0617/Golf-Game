#include "texture.hpp"

Texture::Texture() {}

// texture.cpp

Texture::Texture(Surface* surfPtr) {
  texture = SDL_CreateTextureFromSurface(state.renderer, surfPtr->surface);
}

Texture::Texture(Surface& surfRef) : Texture(&surfRef) { }  // delegate to pointer version

Texture::Texture(const Surface& surfRef) : Texture(const_cast<Surface*>(&surfRef)) { }
// or better, ensure surfRef.getSDL() is non-const or use mutable

Texture::Texture(const std::optional<Surface>& surfOpt) {
  if (surfOpt) {
    texture = SDL_CreateTextureFromSurface(state.renderer, surfOpt->surface);
    if (!texture) {
        // error
    }
  } else {
    texture = nullptr;
  }
}

Texture::Texture(const std::optional<Surface*> surfOpt) {
  if (surfOpt && *surfOpt && (*surfOpt)->surface) {
    texture = SDL_CreateTextureFromSurface(state.renderer, (*surfOpt)->surface);
    if (!texture) {
      SDL_Log("Failed to create texture: %s", SDL_GetError());
    }
  } else {
    texture = nullptr;
  }
}


Texture::~Texture() {
  if (texture) {
    SDL_DestroyTexture(texture);
    texture = nullptr;
  }
}


// bool Texture::initTexture(int width, int height) {
//   bool state = SDL_CreateTexture(width, height);
// }
