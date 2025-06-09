#include "main.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL_CLasses.h>
#include <SDL_Util.h>

Window window;
int fps = 60; // make this a macro if the fps is fixed

void run_input_dispay(void);
void render_screen(void);

int main(int argc, char* args[]) {
    //Init SDL Stuff
    SDL_Init(SDL_INIT_EVERYTHING);

    window.init(1280, 720, "Input Display");

    run_input_dispay();

    // Save and clean everything
    SDL_DestroyWindow(window.window); // This closed the window
    SDL_DestroyRenderer(window.renderer);
    SDL_Quit(); // Closed the SDL program
    IMG_Quit();
    Mix_Quit();
    return 0;
}

void run_input_dispay()
{
    SDL_Event event;
    Uint32 starting_tick;
    
    SDL_Joystick *joy_1 = NULL;
    if (SDL_NumJoysticks() < 1)
    {
        std::cout << "No Joy\n";
    }
    else
    {
        joy_1 = SDL_JoystickOpen(0);
    }

    while(true)
    {
        starting_tick = SDL_GetTicks();

        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return;
            }

            if (event.type == SDL_MOUSEBUTTONUP)
            {

            }

            if (event.type == SDL_KEYDOWN)
            {

            }

            if (event.type == SDL_JOYHATMOTION)
            {
                if (event.jhat.value == SDL_HAT_LEFT)
                {
                    std::cout << "joy left\n";
                }

                if (event.jhat.value == SDL_HAT_RIGHT)
                {
                    std::cout << "joy right\n";
                }

                if (event.jhat.value == SDL_HAT_UP)
                {
                    std::cout << "joy up\n";
                }

                if (event.jhat.value == SDL_HAT_DOWN)
                {
                    std::cout << "joy down\n";
                }

                if (event.jhat.value == SDL_HAT_RIGHTUP)
                {
                    std::cout << "joy up right\n";
                }

                if (event.jhat.value == SDL_HAT_RIGHTDOWN)
                {
                    std::cout << "joy down right\n";
                }

                if (event.jhat.value == SDL_HAT_LEFTUP)
                {
                    std::cout << "joy up left\n";
                }

                if (event.jhat.value == SDL_HAT_LEFTDOWN)
                {
                    std::cout << "joy down left\n";
                }
            }

            if (event.type == SDL_JOYBUTTONDOWN)
            {
                if (event.jbutton.button == 0)
                {
                    std::cout << "joy A\n";
                }

                if (event.jbutton.button == 3)
                {
                    std::cout << "joy B\n";
                }

                if (event.jbutton.button == 5)
                {
                    std::cout << "joy C\n";
                }

                if (event.jbutton.button == 4)
                {
                    std::cout << "joy D\n";
                }
            }
        }

        render_screen();

        frame_cap(fps, starting_tick);
    }
}

void render_screen(void)
{
    window.clear_render();

    window.render();
}