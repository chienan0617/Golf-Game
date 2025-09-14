#include "Vector2.hpp"
#include <cmath>

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2 Vector2::operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
Vector2 Vector2::operator-(const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
Vector2 Vector2::operator*(float s) const { return Vector2(x * s, y * s); }
Vector2 Vector2::operator/(float s) const { return Vector2(x / s, y / s); }

float Vector2::dot(const Vector2& v) const { return x * v.x + y * v.y; }
float Vector2::length() const { return std::sqrt(x * x + y * y); }
Vector2 Vector2::normalized() const {
  float len = length();
  return (len == 0) ? Vector2(0, 0) : (*this) / len;
}

std::ostream& operator<<(std::ostream& os, const Vector2& v) {
  os << "(" << v.x << ", " << v.y << ")";
  return os;
}
