#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include "vk_base/vk_base.h"


bool handleMessage() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return false;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    return false;
                }
                break;
        }
    }

}

int main() {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *_window;
    _window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 500, SDL_WINDOW_RESIZABLE);

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }
    }

    VulkanContext* context = initVulkan();



    SDL_DestroyWindow(_window);
    SDL_Quit();

return 0;


    

}
