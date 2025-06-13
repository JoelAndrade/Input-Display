#include "input_display_class.h"
#include "common.h"

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

void InputDisplay::resize()
{
    Stick::resize(window);
    Button::resize(window);
}

InputDisplay::~InputDisplay()
{
    Stick::~Stick();
    Button::~Button();
}
