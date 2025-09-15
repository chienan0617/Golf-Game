#include "root.hpp"

RootObject::RootObject(const char* name) : DrawableComponent(name) {
  size = Size(100, 100);
  initPixmap();
  pixmap->fillRect(0, 0, 100, 100, Color(16, 196, 32, 255));
  initTexture();
}

void RootObject::render() {
  texture->render(NULL, NULL);
  SDL_Log("rendering");
}
