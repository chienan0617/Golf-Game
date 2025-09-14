#include "../base.hpp"
#include "game_object.hpp"

#include "object_registry.hpp"
#include <algorithm>

std::vector<GameObject> ObjectRegistry::objects;

void ObjectRegistry::add(const GameObject& obj) {
  objects.push_back(obj);
}

void ObjectRegistry::remove(const GameObject& obj) {
  objects.erase(
    std::remove_if(
      objects.begin(), objects.end(), [&](const GameObject& o) {
        return o.name == obj.name;
      }
    ),
    objects.end()
  );
}

GameObject* ObjectRegistry::get(const char* name) {
  for (auto& obj : objects) {
    if (obj.name == name) return &obj;
  }
  return nullptr;
}
