#include "object_manager.hpp"
#include "object_registry.hpp"
#include <string.h>

namespace ObjectManager {
  void onCreate() {

  }

  void onUpdate() {
    for (auto &obj : ObjectRegistry::objects) {
      obj.update();
    }
  }

  void onRender() {
    // 印出物件數量
    SDL_Log("Object count: %zu", ObjectRegistry::objects.size());
    SDL_Log("Object count: %s", ObjectRegistry::objects.at(0).name);

    for (auto &obj : ObjectRegistry::objects) {
      if (obj.isShown) obj.render();
    }
  }

  void onEnd() {
    for (auto &obj : ObjectRegistry::objects) {
      obj.end();
      obj.dispose();
    }

    ObjectRegistry::objects.clear();
  }
}
