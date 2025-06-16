#include "main.h"
#include "classes/stick_class.h"
#include "classes/input_display_class.h"

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL_CLasses.h>
#include <SDL_Util.h>

#define CONCAT(button_letter, num) button_letter##num
#define RENDER_BUTTON_STATE(button_state, button_letter)\
    if (button_state)\
        input_display.CONCAT(button_letter, 2).render();\
    else\
        input_display.CONCAT(button_letter, 1).render();

#define FPS (120)
#define STICK_BUFFER (FPS/20)

// aspect ratio (3:1)

Window window;
InputDisplay input_display;

TextureImage reference;

void run_input_dispay(void);
void render_screen(void);
static void init_sprites(void);
static bool persist(bool condition, int *counter);

int main(int argc, char* args[]) {
    //Init SDL Stuff
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1"); // Allow background joy stick inputs
    window.init(840, 280, "Input Display", (SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN));
    window.render_color = SDL_violet;
    input_display.init(&window);

    // init_sprites();
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
        return;
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

            if (event.type == SDL_WINDOWEVENT)
            {
                if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    window.set_window_size(3 * event.window.data2, event.window.data2); // data2 is window height
                    input_display.resize();
                }
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
                    input_display.A_pressed = true;
                }

                if (event.jbutton.button == 3)
                {
                    input_display.B_pressed = true;
                }

                if (event.jbutton.button == 5)
                {
                    input_display.C_pressed = true;
                }

                if (event.jbutton.button == 4)
                {
                    input_display.D_pressed = true;
                }
            }

            if (event.type == SDL_JOYBUTTONUP)
            {
                if (event.jbutton.button == 0)
                {
                    input_display.A_pressed = false;
                }

                if (event.jbutton.button == 3)
                {
                    input_display.B_pressed = false;
                }

                if (event.jbutton.button == 5)
                {
                    input_display.C_pressed = false;
                }

                if (event.jbutton.button == 4)
                {
                    input_display.D_pressed = false;
                }
            }


        }

        // Determine the state of the stick 
        input_display.stick_state = Nuetral;
        if (persist(left_hold, &left_counter))
        {
            input_display.stick_state = West;
        }

        if (persist(right_hold, &right_counter))
        {
            input_display.stick_state = East;
        }

        if (persist(up_hold, &up_counter))
        {
            input_display.stick_state = North;
        }
        if (persist(down_hold, &down_counter))
        {
            input_display.stick_state = South;
        }
        if (persist(up_left_hold, &up_left_counter))
        {
            input_display.stick_state = North_West;
        }
        if (persist(up_right_hold, &up_right_counter))
        {
            input_display.stick_state = North_East;
        }
        if (persist(down_left_hold, &down_left_counter))
        {
            input_display.stick_state = South_West;
        }
        if (persist(down_right_hold, &down_right_counter))
        {
            input_display.stick_state = South_East;
        }

        render_screen();

        frame_cap(FPS, starting_tick);
    }
}

void render_screen()
{
    window.clear_render();

    switch (input_display.stick_state)
    {
    case North:
        input_display.N.render();
        // N.render();
        break;
    
    case South:
        input_display.S.render();
        break;

    case East:
        input_display.E.render();
        break;

    case West:
        input_display.W.render();
        break;

    case North_West:
        input_display.NW.render();
        break;
    
    case North_East:
        input_display.NE.render();
        break;

    case South_West:
        input_display.SW.render();
        break;

    case South_East:
        input_display.SE.render();
        break;

    default: // Nuetral
        input_display.O.render();
        break;
    }

    RENDER_BUTTON_STATE(input_display.A_pressed, A);
    RENDER_BUTTON_STATE(input_display.B_pressed, B);
    RENDER_BUTTON_STATE(input_display.C_pressed, C);
    input_display.DX.render();

    if (input_display.D_pressed)
        reference.render();

    window.render();
}

static void init_sprites(void)
{
    reference.init(window.renderer, "images/sprites/00.png", 3.0, 83, 26);
    reference.set_alpha(100);
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
