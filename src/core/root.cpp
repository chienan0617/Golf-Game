#include "root.hpp"
#include "../base/state.hpp"

// // root.cpp
// RootObject::RootObject(const char* name) : DrawableComponent(name) {
//   size = Size(100, 100);
//   initPixmap(); // 建立 pixmap，預設格式例如 SDL_PIXELFORMAT_RGBA32
//   pixmap->fillRect(0, 0, 100, 100, Color(16, 196, 32, 255));

//   initTexture(); // 建立 texture（一次）
//   texture->updateFromPixmap(*pixmap); // 初始把 pixmap 資料貼到 texture

//   dst = SDL_FRect{ 0.0f, 0.0f, (float)size.width, (float)size.height };
//   dirty = false;
// }

// void RootObject::render() {
//   // 若 pixmap 有變，先更新到 texture（只在需要時）
//   if (dirty && texture) {
//     texture->updateFromPixmap(*pixmap);
//     dirty = false;
//   }

//   // draw the texture
//   if (texture) {
//     texture->render(&dst, nullptr); // 你的 wrapper 裡應該呼叫 SDL_RenderCopyF 或 SDL_RenderCopy
//   } else {
//     // fallback: 直接用 renderer 畫（debug）
//     SDL_SetRenderDrawColor(state.renderer, 16, 196, 32, 128);
//     SDL_RenderFillRect(state.renderer, &dst);
//   }
// }
