#pragma once
#include <vector>
#include <memory>
#include <string>
#include "game_object.hpp"

class ObjectRegistry {
public:
  // 加入 unique_ptr
  static void add(std::unique_ptr<GameObject> obj);

  // 便利的 template helper：直接建構派生類
  template<typename T, typename... Args>
  static T* addObject(Args&&... args) {
    static_assert(std::is_base_of<GameObject, T>::value, "T must derive from GameObject");
    auto ptr = std::make_unique<T>(std::forward<Args>(args)...);
    T* raw = ptr.get();
    add(std::move(ptr));
    return raw;
  }

  static void removeByName(const std::string& name);
  static GameObject* get(const std::string& name);

  // 正確的 static 成員宣告（不要用 extern 這樣放在 class 中）
  static std::vector<std::unique_ptr<GameObject>> objects;
private:
  ObjectRegistry() = delete;
};
