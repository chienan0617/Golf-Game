#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include "base/game.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
  Game game;
  game.run();

  return 0;
}

// int main(int argc, char* argv[]) {
//   Init::initSDL();
//   Init::createWindow("Test", 640, 480);
//   Init::createRenderer();

//     // // Initialize SDL
//     // if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
//     //     SDL_Log("SDL_Init Error: %s", SDL_GetError());
//     //     return 1;
//     // }

//     // Create a window
//     // SDL_Window* window = SDL_CreateWindow("SDL3 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
//     // if (!window) {
//     //     SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
//     //     SDL_Quit();
//     //     return 1;
//     // }

//     // Create a renderer
//     // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//     // if (!renderer) {
//     //     SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
//     //     SDL_DestroyWindow(window);
//     //     SDL_Quit();
//     //     return 1;
//     // }

//     // Define a rectangle (x, y, width, height)
//     SDL_FRect rect = {100.0f, 100.0f, 200.0f, 150.0f};

//     // Event loop
//     SDL_Event e;
//     // bool quit = false;
//     bool printMessage = false;

//     while (State::running) {
//         // Handle events
//         while (SDL_PollEvent(&e)) {
//             if (e.type == SDL_EVENT_QUIT) {
//                 State::running = false;
//             } else if (e.type == SDL_EVENT_KEY_DOWN) {
//                 if (e.key.scancode == SDL_SCANCODE_PRINTSCREEN) {
//                     printMessage = true;
//                 }
//             }
//         }

//         // Clear the screen
//         SDL_SetRenderDrawColor(State::renderer, 0, 0, 0, 255); // Black
//         SDL_RenderClear(State::renderer);

//         // Set the draw color to green
//         SDL_SetRenderDrawColor(State::renderer, 0, 255, 0, 255); // Green
//         SDL_RenderFillRect(State::renderer, &rect);

//         // Present the renderer
//         SDL_RenderPresent(State::renderer);

//         // Print message if Print Screen key was pressed
//         if (printMessage) {
//             std::cout << "Hello, World!" << std::endl;
//             printMessage = false; // Reset flag
//         }

//         // Delay to control frame rate
//         SDL_Delay(16); // Approximately 60 FPS
//     }

//     // Clean up
//     SDL_DestroyRenderer(State::renderer);
//     SDL_DestroyWindow(State::window);
//     SDL_Quit();

//     return 0;
// }
