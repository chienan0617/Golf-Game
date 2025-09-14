#include "color.hpp"
#include "stdlib.h"

Color::Color(uchar r, uchar g, uchar b, uchar a) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

Color Color::withR(uchar v) {
  return Color(v, this->g, this->b, this->a);
}

Color Color::withG(uchar v) {
  return Color(this->r, v, this->b, this->a);
}

Color Color::withB(uchar v) {
  return Color(this->r, this->g, v, this->a);
}

Color Color::withA(uchar v) {
  return Color(this->r, this->g, this->b, v);
}

void Color::set(Color c) {
  this->r = c.r;
  this->g = c.g;
  this->b = c.b;
  this->a = c.a;
}

void Color::set(uchar r, uchar g, uchar b, uchar a) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

Color Color::random() {
  return Color(rand() % 256, rand() % 256, rand() % 256, 255);
}

Color::~Color() {}
