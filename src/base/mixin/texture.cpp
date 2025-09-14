#include "texture.hpp"
#include "../state.hpp"
#include <stdexcept>

Texture::Texture(SDL_Renderer* renderer, int width, int height, SDL_PixelFormat format, SDL_TextureAccess access)
  : texture(nullptr)
{
  texture = SDL_CreateTexture(renderer, format, access, width, height);
  if (!texture) {
    throw std::runtime_error(std::string("Failed to create SDL Texture: ") + SDL_GetError());
  }
}

Texture::~Texture() {
  if (texture) {
    SDL_DestroyTexture(texture);
    texture = nullptr;
  }
}

Texture::Texture(Texture&& other) noexcept
  : texture(other.texture)
{
  other.texture = nullptr;
}

Texture& Texture::operator=(Texture&& other) noexcept {
  if (this != &other) {
    if (texture) {
      SDL_DestroyTexture(texture);
    }
    texture = other.texture;
    other.texture = nullptr;
  }
  return *this;
}

int Texture::getWidth() const {
  float w = 0;
  if (texture) {
    SDL_GetTextureSize(texture, &w, nullptr);
  }
  return w;
}

int Texture::getHeight() const {
  float h = 0;
  if (texture) {
    SDL_GetTextureSize(texture, nullptr, &h);
  }
  return h;
}

Texture Texture::fromPixmap(SDL_Renderer* renderer, const Pixmap& pixmap) {
  SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, pixmap.surface);
  if (!tex) {
    throw std::runtime_error(std::string("SDL_CreateTextureFromSurface failed: ") + SDL_GetError());
  }
  Texture t(state.renderer, 0, 0, SDL_PIXELFORMAT_UNKNOWN, SDL_TEXTUREACCESS_STATIC);  // dummy init
  t.texture = tex;
  return t;
}

void Texture::updateFromPixmap(const Pixmap& pixmap) {
  if (!texture) return;
  SDL_UpdateTexture(texture, nullptr, pixmap.surface->pixels, pixmap.getPitch());
}

void Texture::render(SDL_Renderer* renderer, const SDL_FRect* dst, const SDL_FRect* src) {
  if (!texture) return;
  SDL_RenderTexture(renderer, texture, src, dst);
}

void Texture::setAsRenderTarget(SDL_Renderer* renderer) {
  if (!texture) return;
  if (SDL_SetRenderTarget(renderer, texture) != 0) {
    throw std::runtime_error(std::string("SDL_SetRenderTarget failed: ") + SDL_GetError());
  }
}

void Texture::resetRenderTarget(SDL_Renderer* renderer) {
  SDL_SetRenderTarget(renderer, nullptr);
}
