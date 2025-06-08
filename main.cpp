#include "main.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL_CLasses.h>
#include <SDL_Util.h>

Window window;
int fps = 60; // make this a macro if the fps is fixed

int main(int argc, char* args[]) {
    //Init SDL Stuff
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);
    SDL_ShowCursor(SDL_DISABLE);

    std::cout << "Hello World" << std::endl;

    // Save and clean everything
    SDL_DestroyWindow(window.window); // This closed the window
    SDL_DestroyRenderer(window.renderer);
    SDL_Quit(); // Closed the SDL program
    IMG_Quit();
    Mix_Quit();
    return 0;
}
