#pragma once
#include <vector>
#include <string>
#include "../base.hpp"
#include "game_object.hpp"

class ObjectRegistry {
public:
  static void add(const GameObject& obj);
  static void remove(const GameObject& obj);
  static GameObject* get(const char* name);
  static std::vector<GameObject> objects;
private:
};
