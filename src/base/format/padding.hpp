#include "../base.hpp"

class Padding {
public:
  int top, bottom, right, left;

  Padding();
  Padding(int top, int bottom, int right, int left);
  Padding(int vertical, int horizon);
};
