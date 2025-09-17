#pragma once
#include "../base.hpp"
#include "../object/game_object.hpp"
#include "../format/size.hpp"
#include "../math/vector2.hpp"

class SizedComponent : public GameObject {
public:
  Size size;
  Vector2 position;

  explicit SizedComponent(const char* name);
};
