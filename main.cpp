#include "main.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL_CLasses.h>
#include <SDL_Util.h>

#define CONCAT(button_letter, num) button_letter##num
#define RENDER_BUTTON_STATE(button_state, button_letter)\
    if (button_state)\
    CONCAT(button_letter, 2).render();\
    else\
    CONCAT(button_letter, 1).render();

#define FPS (120)
#define STICK_BUFFER (FPS/20)

Window window;

TextureImage reference;

TextureImage N;
TextureImage E;
TextureImage S;
TextureImage W;
TextureImage NW;
TextureImage NE;
TextureImage SW;
TextureImage SE;
TextureImage O;

TextureImage A1;
TextureImage A2;
TextureImage B1;
TextureImage B2;
TextureImage C1;
TextureImage C2;
TextureImage D1;
TextureImage D2;
TextureImage DX;

void run_input_dispay(void);
void render_screen(stick_state_e stick_state, bool a_button, bool b_button, bool c_button, bool d_button);
static void init_sprites(void);
static bool persist(bool condition, int *counter);

int main(int argc, char* args[]) {
    //Init SDL Stuff
    SDL_Init(SDL_INIT_EVERYTHING);

    window.init(1280, 720, "Input Display");

    init_sprites();
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

    stick_state_t stick_state = Nuetral;
    bool a_button = false;
    bool b_button = false;
    bool c_button = false;
    bool d_button = false;

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
                    a_button = true;
                }

                if (event.jbutton.button == 3)
                {
                    b_button = true;
                }

                if (event.jbutton.button == 5)
                {
                    c_button = true;
                }

                if (event.jbutton.button == 4)
                {
                    d_button = true;
                }
            }

            if (event.type == SDL_JOYBUTTONUP)
            {
                if (event.jbutton.button == 0)
                {
                    a_button = false;
                }

                if (event.jbutton.button == 3)
                {
                    b_button = false;
                }

                if (event.jbutton.button == 5)
                {
                    c_button = false;
                }

                if (event.jbutton.button == 4)
                {
                    d_button = false;
                }
            }


        }

        // Determine the state of the stick 
        stick_state = Nuetral;
        if (persist(left_hold, &left_counter))
        {
            stick_state = West;
        }

        if (persist(right_hold, &right_counter))
        {
            stick_state = East;
        }

        if (persist(up_hold, &up_counter))
        {
            stick_state = North;
        }
        if (persist(down_hold, &down_counter))
        {
            stick_state = South;
        }
        if (persist(up_left_hold, &up_left_counter))
        {
            stick_state = North_East;
        }
        if (persist(up_right_hold, &up_right_counter))
        {
            stick_state = North_West;
        }
        if (persist(down_left_hold, &down_left_counter))
        {
            stick_state = South_West;
        }
        if (persist(down_right_hold, &down_right_counter))
        {
            stick_state = South_East;
        }

        render_screen(stick_state, a_button, b_button, c_button, d_button);

        frame_cap(FPS, starting_tick);
    }
}

void render_screen(stick_state_e stick_state, bool a_button, bool b_button, bool c_button, bool d_button)
{
    window.clear_render();

    switch (stick_state)
    {
    case North:
        N.render();
        break;
    
    case South:
        S.render();
        break;

    case East:
        E.render();
        break;

    case West:
        W.render();
        break;

    case North_West:
        NW.render();
        break;
    
    case North_East:
        NE.render();
        break;

    case South_West:
        SW.render();
        break;

    case South_East:
        SE.render();
        break;

    default: // Nuetral
        O.render();
        break;
    }

    RENDER_BUTTON_STATE(a_button, A);
    RENDER_BUTTON_STATE(b_button, B);
    RENDER_BUTTON_STATE(c_button, C);
    DX.render();

    window.render();
}

static void init_sprites(void)
{
    reference.init(window.renderer, "sprites/00.png");

    N.init(window.renderer, "sprites/N.png", 3.0, 0, 0);
    E.init(window.renderer, "sprites/E.png", 3.0, 0, 0);
    S.init(window.renderer, "sprites/S.png", 3.0, 0, 0);
    W.init(window.renderer, "sprites/W.png", 3.0, 0, 0);
    NW.init(window.renderer, "sprites/NW.png", 3.0, 0, 0);
    NE.init(window.renderer, "sprites/NE.png", 3.0, 0, 0);
    SW.init(window.renderer, "sprites/SW.png", 3.0, 0, 0);
    SE.init(window.renderer, "sprites/SE.png", 3.0, 0, 0);
    O.init(window.renderer, "sprites/O.png", 3.0, 0, 0);
    
    A1.init(window.renderer, "sprites/A1.png", 3.0, 200, 0);
    A2.init(window.renderer, "sprites/A2.png", 3.0, 200, 0);
    B1.init(window.renderer, "sprites/B1.png", 3.0, 400, 0);
    B2.init(window.renderer, "sprites/B2.png", 3.0, 400, 0);
    C1.init(window.renderer, "sprites/C1.png", 3.0, 600, 0);
    C2.init(window.renderer, "sprites/C2.png", 3.0, 600, 0);
    D1.init(window.renderer, "sprites/D1.png", 3.0, 800, 0);
    D2.init(window.renderer, "sprites/D2.png", 3.0, 800, 0);
    DX.init(window.renderer, "sprites/DX.png", 3.0, 800, 0);
}


static bool persist(bool condition, int *counter)
{
    if (condition)
    {
        if (*counter < STICK_BUFFER)
        {
            *counter += 1;
        }
        if (*counter >= STICK_BUFFER)
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
