#include "../base/base.hpp"
#include "../base/object/game_object.hpp"
#include "../base/component/drawable_component.hpp"

class RootObject : public DrawableComponent {
public:
  RootObject(const char* name);

  void render() override;
};
