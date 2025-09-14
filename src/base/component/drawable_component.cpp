#include "drawable_component.hpp"
#include "../state.hpp"

DrawableComponent::DrawableComponent(const char* name) : SizedComponent(name) {
  // this->pixmap = Pixmap(this->size.width, this->size.height);
  // this->texture = NULL;
}

void DrawableComponent::initPixmap(int width, int height) {
  this->pixmap = Pixmap(width, height);
}

void DrawableComponent::initTexture(int width, int height, SDL_PixelFormat format, SDL_TextureAccess access) {
  this->texture = Texture(state.renderer, width, height, format, access);
}
