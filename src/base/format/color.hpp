#include "../base.hpp"

using namespace std;

typedef unsigned char uchar;

class Color {
public:
  uchar r, g, b, a;

  Color(uchar r, uchar g, uchar b, uchar a);
  ~Color();

  Color withR(uchar v);
  Color withG(uchar v);
  Color withB(uchar v);
  Color withA(uchar v);
  void set(Color c);
  void set(uchar r, uchar g, uchar b, uchar a);

  static Color random();
};
