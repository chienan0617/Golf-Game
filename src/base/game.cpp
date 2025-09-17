#include "base.hpp"
#include "game.hpp"
#include "init.hpp"
#include "state.hpp"
#include "system.hpp"
#include "event.hpp"
#include "object/object_manager.hpp"
#include "object/object_registry.hpp"
#include "model/canvas.hpp"
#include "../core/root.hpp"

void Game::run() {
  Game::init();
  Game::loop();
  Game::dispose();
}

void Game::init() {
  Init::initSDL();
  Init::createWindow("Test", 640, 480);
  Init::createRenderer();
  // Init::initDisplayMode(); // ! fatal function!!!
  ObjectManager::onCreate();

  // ObjectRegistry::addObject<RootObject>("New");




  // 檢查 window/renderer 是否存在
  SDL_Log("state.window = %p", (void*)state.window);
  SDL_Log("state.renderer = %p", (void*)state.renderer);

  // 檢查 renderer 的 render target（是否被設成某 texture）
  #if SDL_VERSION_ATLEAST(2,0,0)
  SDL_Texture* rt = SDL_GetRenderTarget(state.renderer);
  SDL_Log("Initial render target = %p", (void*)rt);
  #endif

}

void Game::loop() {
  while (state.running) {
    while(Event::pollEvent(event)) {
      Event::detectQuit(event);
    }

    Canvas::setColor(Color(0, 0, 0, 255)); // 背景色
    Canvas::renderClear();                 // 先清背景
    ObjectManager::onUpdate();             // 更新邏輯
    ObjectManager::onRender();             // 畫物件
    Canvas::renderPresent();               // 顯示到螢幕




    // SDL_FRect debugRect = {10.0f, 10.0f, 100.0f, 100.0f};
    // SDL_SetRenderDrawColor(state.renderer, 16, 196, 32, 255);
    // SDL_RenderFillRect(state.renderer, &debugRect);

    // System::delay(8);
  }

}

void Game::dispose() {
  System::destroyWindow();
  System::destroyRenderer();
  System::quit();
}
