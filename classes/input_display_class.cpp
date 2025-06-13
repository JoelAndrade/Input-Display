#include "input_display_class.h"

InputDisplay::InputDisplay(){}
InputDisplay::InputDisplay(Window *window)
{
    this->window = window;

    Stick::init(window);
    Button::init(window);
}

void InputDisplay::init(Window *window)
{
    this->window = window;

    Stick::init(window);
    Button::init(window);
}

InputDisplay::~InputDisplay()
{
    Stick::~Stick();
    Button::~Button();
}
