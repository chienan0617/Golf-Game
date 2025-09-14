#include "size.hpp"

Size::Size(int width, int height) {
  this->width = width;
  this->height = height;
}

Size::Size() {
  this->width = 0;
  this->height = 0;
}

Size Size::withWidth(int width) {
  return Size(width, 0);
}

Size Size::withHeight(int height) {
  return Size(0, height);
}
