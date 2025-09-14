#include "vector4.hpp"
#include <cmath>

Vector4::Vector4() : x(0), y(0), z(0), w(0) {}
Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Vector4 Vector4::operator+(const Vector4& v) const { return Vector4(x + v.x, y + v.y, z + v.z, w + v.w); }
Vector4 Vector4::operator-(const Vector4& v) const { return Vector4(x - v.x, y - v.y, z - v.z, w - v.w); }
Vector4 Vector4::operator*(float s) const { return Vector4(x * s, y * s, z * s, w * s); }
Vector4 Vector4::operator/(float s) const { return Vector4(x / s, y / s, z / s, w / s); }

float Vector4::dot(const Vector4& v) const { return x * v.x + y * v.y + z * v.z + w * v.w; }
float Vector4::length() const { return std::sqrt(x * x + y * y + z * z + w * w); }
Vector4 Vector4::normalized() const {
  float len = length();
  return (len == 0) ? Vector4(0, 0, 0, 0) : (*this) / len;
}

std::ostream& operator<<(std::ostream& os, const Vector4& v) {
  os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
  return os;
}
