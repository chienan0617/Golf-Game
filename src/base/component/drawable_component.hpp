// #include "../base.hpp"
// #include "../object/game_object.hpp"
#include "sized_component.hpp"

class DrawableComponent : public SizedComponent {
public:
  DrawableComponent(const char* name);
};
