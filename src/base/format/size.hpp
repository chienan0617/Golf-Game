#pragma once
#include "../base.hpp"

class Size {
public:
  int width, height;

  Size(int width, int height);
  Size();

  static Size withWidth(int width);
  static Size withHeight(int height);
};
