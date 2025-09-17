#include "object_manager.hpp"
#include "object_registry.hpp"

namespace ObjectManager {
  void onCreate() {}

  void onUpdate() {
    for (auto &obj : ObjectRegistry::objects) {
      if (obj) obj->update();
    }
  }

  void onRender() {
    for (auto &obj : ObjectRegistry::objects) {
      if (obj && obj->isShown) obj->render();
    }
  }

  void onEnd() {
    for (auto &obj : ObjectRegistry::objects) {
      if (obj) {
        obj->end();
        obj->dispose();
      }
    }
    ObjectRegistry::objects.clear();
  }
}
