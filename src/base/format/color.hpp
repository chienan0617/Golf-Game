#pragma once
#include "../base.hpp"

// typedef unsigned char uchar;

class Color {
public:
  Uint8 r, g, b, a;

  Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  ~Color();

  Color withR(Uint8 v);
  Color withG(Uint8 v);
  Color withB(Uint8 v);
  Color withA(Uint8 v);
  void set(Color c);
  void set(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

  static Color random();
};
