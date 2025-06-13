#include "button_class.h"
#include "common.h"

#define INIT_BUTTON\
    A1.init(window->renderer, "sprites/A1.png", SCALE(3.0), X_SCALE(227), Y_SCALE(131));\
    A2.init(window->renderer, "sprites/A2.png", SCALE(3.0), X_SCALE(227), Y_SCALE(131));\
    B1.init(window->renderer, "sprites/B1.png", SCALE(3.0), X_SCALE(371), Y_SCALE(131));\
    B2.init(window->renderer, "sprites/B2.png", SCALE(3.0), X_SCALE(371), Y_SCALE(131));\
    C1.init(window->renderer, "sprites/C1.png", SCALE(3.0), X_SCALE(515), Y_SCALE(131));\
    C2.init(window->renderer, "sprites/C2.png", SCALE(3.0), X_SCALE(515), Y_SCALE(131));\
    D1.init(window->renderer, "sprites/D1.png", SCALE(3.0), X_SCALE(659), Y_SCALE(131));\
    D2.init(window->renderer, "sprites/D2.png", SCALE(3.0), X_SCALE(659), Y_SCALE(131));\
    DX.init(window->renderer, "sprites/DX.png", SCALE(3.0), X_SCALE(659), Y_SCALE(107));

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

void Button::resize(Window *window)
{
    A1.resize(SCALE(3.0));
    A2.resize(SCALE(3.0));
    B1.resize(SCALE(3.0));
    B2.resize(SCALE(3.0));
    C1.resize(SCALE(3.0));
    C2.resize(SCALE(3.0));
    D1.resize(SCALE(3.0));
    D2.resize(SCALE(3.0));
    DX.resize(SCALE(3.0));

    A1.change_pos(X_SCALE(227), Y_SCALE(131));
    A2.change_pos(X_SCALE(227), Y_SCALE(131));
    B1.change_pos(X_SCALE(371), Y_SCALE(131));
    B2.change_pos(X_SCALE(371), Y_SCALE(131));
    C1.change_pos(X_SCALE(515), Y_SCALE(131));
    C2.change_pos(X_SCALE(515), Y_SCALE(131));
    D1.change_pos(X_SCALE(659), Y_SCALE(131));
    D2.change_pos(X_SCALE(659), Y_SCALE(131));
    DX.change_pos(X_SCALE(659), Y_SCALE(107));
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
