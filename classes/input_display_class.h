#ifndef INPUT_DISPLAY_H
#define INPUT_DISPLAY_H

#include "button_class.h"
#include "stick_class.h"

#include <SDL2/SDL.h>
#include <SDL_Classes.h>

class InputDisplay : public Stick, public Button
{
public:
    Window *window;
    
    InputDisplay();
    InputDisplay(Window *window);

    void init(Window *window);
    void resize();

    ~InputDisplay();
};

#endif // INPUT_DISPLAY_H
