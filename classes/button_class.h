#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <SDL_Classes.h>

#define NUM_ITEMS

class Button
{
public:
    TextureImage A1;
    TextureImage A2;
    TextureImage B1;
    TextureImage B2;
    TextureImage C1;
    TextureImage C2;
    TextureImage D1;
    TextureImage D2;
    TextureImage DX;
    
    bool A_pressed;
    bool B_pressed;
    bool C_pressed;
    bool D_pressed;

    Button();
    Button(Window *window);

    void init(Window *window);
    void resize(Window *window);

    ~Button();
};

#endif // BUTTON_H
