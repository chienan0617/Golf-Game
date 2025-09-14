#include "../base.hpp"
#include "../object/game_object.hpp"

class SizedComponent : public GameObject {
public:
  explicit SizedComponent(const char* name);
};
