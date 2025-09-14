#include "base.hpp"

namespace System {
  void log(const char* msg);
  void destroyWindow();
  void destroyRenderer();
  void quit();
  void delay(int s);
  const char* getError();

  int onError(const char* errmsg);
}
