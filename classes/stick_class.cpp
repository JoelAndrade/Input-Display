#include "stick_class.h"

#include <iostream>

#define INIT_STICK\
    O.init(window->renderer, "sprites/O.png",   3.0,  83, 26);\
    N.init(window->renderer, "sprites/N.png",   3.0,  86,  0);\
    E.init(window->renderer, "sprites/E.png",   3.0, 100, 32);\
    S.init(window->renderer, "sprites/S.png",   3.0,  80, 42);\
    W.init(window->renderer, "sprites/W.png",   3.0,   0, 32);\
    NW.init(window->renderer, "sprites/NW.png", 3.0,  18, 18);\
    NE.init(window->renderer, "sprites/NE.png", 3.0, 100, 18);\
    SW.init(window->renderer, "sprites/SW.png", 3.0,  24, 43);\
    SE.init(window->renderer, "sprites/SE.png", 3.0, 100, 43);

Stick::Stick()
{
    stick_state = Nuetral;
}
Stick::Stick(Window *window)
{
    stick_state = Nuetral;
    INIT_STICK;
}

void Stick::init(Window *window)
{
    stick_state = Nuetral;
    INIT_STICK;
}

Stick::~Stick()
{
    O.~TextureImage();
    N.~TextureImage();
    E.~TextureImage();
    S.~TextureImage();
    W.~TextureImage();
    NW.~TextureImage();
    NE.~TextureImage();
    SW.~TextureImage();
    SE.~TextureImage();
}
