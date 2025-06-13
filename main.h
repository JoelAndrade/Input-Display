#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL_CLasses.h>

#include <iostream>

extern Window window;
extern int fps;

typedef enum stick_state_e
{
    North,
    South,
    East,
    West,
    North_West,
    North_East,
    South_West,
    South_East,
    Nuetral
} stick_state_t;

#endif // MAIN_H 