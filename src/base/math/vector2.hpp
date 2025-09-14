#pragma once
#include <iostream>

class Vector2 {
public:
  float x, y;

  Vector2();
  Vector2(float x, float y);

  Vector2 operator+(const Vector2& v) const;
  Vector2 operator-(const Vector2& v) const;
  Vector2 operator*(float s) const;
  Vector2 operator/(float s) const;

  float dot(const Vector2& v) const;
  float length() const;
  Vector2 normalized() const;

  friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
};
