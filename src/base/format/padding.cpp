#include "padding.hpp"

Padding::Padding() {
  this->bottom = 0;
  this->left = 0;
  this->right = 0;
  this->top = 0;
}

Padding::Padding(int top, int bottom, int right, int left) {
  this->bottom = bottom;
  this->left = left;
  this->right = right;
  this->top = top;
}

Padding::Padding(int vertical, int horizon) {
  this->right = horizon;
  this->left = horizon;
  this->bottom = vertical;
  this->top = vertical;
}
