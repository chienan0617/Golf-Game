#include "size.hpp"

Size::Size(int width, int height) {
  this->width = width;
  this->height = height;
}

Size Size::withWidth(int width) {
  return Size(width, 0);
}

Size Size::withHeight(int height) {
  return Size(0, height);
}
