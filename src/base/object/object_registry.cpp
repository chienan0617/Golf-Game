#include "object_registry.hpp"
#include <algorithm>

// 定義 static 成員（一定要在 cpp 中定義一次）
std::vector<std::unique_ptr<GameObject>> ObjectRegistry::objects;

void ObjectRegistry::add(std::unique_ptr<GameObject> obj) {
  objects.push_back(std::move(obj));
}

void ObjectRegistry::removeByName(const std::string& name) {
  objects.erase(
    std::remove_if(objects.begin(), objects.end(),
      [&](const std::unique_ptr<GameObject>& o) {
        return o && o->name == name;
      }),
    objects.end());
}

GameObject* ObjectRegistry::get(const std::string& name) {
  for (auto& o : objects) {
    if (o && o->name == name) return o.get();
  }
  return nullptr;
}
