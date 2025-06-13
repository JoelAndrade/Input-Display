#include "button_class.h"

#define INIT_BUTTON\
    A1.init(window->renderer, "sprites/A1.png", 3.0, 227, 131);\
    A2.init(window->renderer, "sprites/A2.png", 3.0, 227, 140);\
    B1.init(window->renderer, "sprites/B1.png", 3.0, 371, 131);\
    B2.init(window->renderer, "sprites/B2.png", 3.0, 371, 140);\
    C1.init(window->renderer, "sprites/C1.png", 3.0, 515, 131);\
    C2.init(window->renderer, "sprites/C2.png", 3.0, 515, 140);\
    D1.init(window->renderer, "sprites/D1.png", 3.0, 659, 131);\
    D2.init(window->renderer, "sprites/D2.png", 3.0, 659, 140);\
    DX.init(window->renderer, "sprites/DX.png", 3.0, 659, 107);

Button::Button() {}
Button::Button(Window *window)
{
    A_pressed = false;
    B_pressed = false;
    C_pressed = false;
    D_pressed = false;

    INIT_BUTTON;
}

void Button::init(Window *window)
{
    A_pressed = false;
    B_pressed = false;
    C_pressed = false;
    D_pressed = false;

    INIT_BUTTON;
}

Button::~Button()
{
    A1.~TextureImage();
    A2.~TextureImage();
    B1.~TextureImage();
    B2.~TextureImage();
    C1.~TextureImage();
    C2.~TextureImage();
    D1.~TextureImage();
    D2.~TextureImage();
    DX.~TextureImage();
}
