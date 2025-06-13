#ifndef STICK_H
#define STICK_H

#include <SDL2/SDL.h>
#include <SDL_CLasses.h>

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

class Stick
{
public:
    TextureImage N;
    TextureImage E;
    TextureImage S;
    TextureImage W;
    TextureImage NW;
    TextureImage NE;
    TextureImage SW;
    TextureImage SE;
    TextureImage O;

    stick_state_t stick_state;

    Stick();
    Stick(Window *window);

    void init(Window *window);
    void resize(Window *window);

    ~Stick();
};

#endif // STICK_H
