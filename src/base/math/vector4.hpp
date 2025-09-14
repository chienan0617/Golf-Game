#pragma once
#include <iostream>

class Vector4 {
public:
  float x, y, z, w;

  Vector4();
  Vector4(float x, float y, float z, float w);

  Vector4 operator+(const Vector4& v) const;
  Vector4 operator-(const Vector4& v) const;
  Vector4 operator*(float s) const;
  Vector4 operator/(float s) const;

  float dot(const Vector4& v) const;
  float length() const;
  Vector4 normalized() const;

  friend std::ostream& operator<<(std::ostream& os, const Vector4& v);
};
