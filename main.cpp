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
static bool persist(bool condition, int *counter);

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
    
    int left_counter       = 0;
    int right_counter      = 0;
    int up_counter         = 0;
    int down_counter       = 0;
    int up_left_counter    = 0;
    int up_right_counter   = 0;
    int down_left_counter  = 0;
    int down_right_counter = 0;

    bool left_hold       = false;
    bool right_hold      = false;
    bool up_hold         = false;
    bool down_hold       = false;
    bool up_left_hold    = false;
    bool up_right_hold   = false;
    bool down_left_hold  = false;
    bool down_right_hold = false;
    
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
                left_hold       = false;
                right_hold      = false;
                up_hold         = false;
                down_hold       = false;
                up_left_hold    = false;
                up_right_hold   = false;
                down_left_hold  = false;
                down_right_hold = false;

                if (event.jhat.value == SDL_HAT_CENTERED)
                {
                    std::cout << "joy center\n";
                }
                if (event.jhat.value == SDL_HAT_LEFT)
                {
                    left_hold = true;
                }
                if (event.jhat.value == SDL_HAT_RIGHT)
                {
                    right_hold = true;
                }
                if (event.jhat.value == SDL_HAT_UP)
                {
                    up_hold = true;
                }
                if (event.jhat.value == SDL_HAT_DOWN)
                {
                    down_hold = true;
                }
                if (event.jhat.value == SDL_HAT_LEFTUP)
                {
                    up_left_hold = true;
                }
                if (event.jhat.value == SDL_HAT_RIGHTUP)
                {
                    up_right_hold = true;
                }
                if (event.jhat.value == SDL_HAT_LEFTDOWN)
                {
                    down_left_hold = true;
                }
                if (event.jhat.value == SDL_HAT_RIGHTDOWN)
                {
                    down_right_hold = true;
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

        if (persist(left_hold, &left_counter))
        {
            std::cout << "joy left\n";
        }

        if (persist(right_hold, &right_counter))
        {
            std::cout << "joy right\n";
        }

        if (persist(up_hold, &up_counter))
        {
            std::cout << "joy up\n";
        }
        if (persist(down_hold, &down_counter))
        {
            std::cout << "joy down\n";
        }
        if (persist(up_left_hold, &up_left_counter))
        {
            std::cout << "joy up left\n";
        }
        if (persist(up_right_hold, &up_right_counter))
        {
            std::cout << "joy up right\n";
        }
        if (persist(down_left_hold, &down_left_counter))
        {
            std::cout << "joy down left\n";
        }
        if (persist(down_right_hold, &down_right_counter))
        {
            std::cout << "joy down right\n";
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

static bool persist(bool condition, int *counter)
{
    if (condition)
    {
        if (*counter < 3)
        {
            *counter += 1;
        }
        if (*counter >= 3)
        {
            return true;
        }
    }
    else
    {
        *counter = 0;
    }

    return false;
}
