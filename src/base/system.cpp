#include "system.hpp"
#include "state.hpp"

namespace System {
  void log(const char* msg) {
    SDL_Log(msg);
  }

  void destroyWindow() {
    SDL_DestroyWindow(State::window);
  }

  void quit() {
    State::running = false;
    SDL_Quit();
  }

  void delay(int s) {
    SDL_Delay(s);
  }

  const char* getError() {
    return SDL_GetError();
  }

  int onError(const char* errmsg) {
    SDL_Log(errmsg);
    destroyWindow();
    quit();
    return 1;
  }
}
