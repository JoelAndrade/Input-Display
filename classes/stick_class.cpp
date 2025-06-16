#include "stick_class.h"
#include "common.h"

#define INIT_STICK\
    O.init(window->renderer,  "images/sprites/O.png",  SCALE(3.0), X_SCALE( 83), Y_SCALE(26));\
    N.init(window->renderer,  "images/sprites/N.png",  SCALE(3.0), X_SCALE( 86), Y_SCALE( 0));\
    E.init(window->renderer,  "images/sprites/E.png",  SCALE(3.0), X_SCALE(100), Y_SCALE(32));\
    S.init(window->renderer,  "images/sprites/S.png",  SCALE(3.0), X_SCALE( 80), Y_SCALE(42));\
    W.init(window->renderer,  "images/sprites/W.png",  SCALE(3.0), X_SCALE(  0), Y_SCALE(32));\
    NW.init(window->renderer, "images/sprites/NW.png", SCALE(3.0), X_SCALE( 18), Y_SCALE(18));\
    NE.init(window->renderer, "images/sprites/NE.png", SCALE(3.0), X_SCALE(100), Y_SCALE(18));\
    SW.init(window->renderer, "images/sprites/SW.png", SCALE(3.0), X_SCALE( 24), Y_SCALE(43));\
    SE.init(window->renderer, "images/sprites/SE.png", SCALE(3.0), X_SCALE(100), Y_SCALE(43));

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

void Stick::resize(Window *window)
{
    O.resize( SCALE(3.0));
    N.resize( SCALE(3.0));
    E.resize( SCALE(3.0));
    S.resize( SCALE(3.0));
    W.resize( SCALE(3.0));
    NW.resize(SCALE(3.0));
    NE.resize(SCALE(3.0));
    SW.resize(SCALE(3.0));
    SE.resize(SCALE(3.0));

    O.change_pos( X_SCALE( 83), Y_SCALE(26));
    N.change_pos( X_SCALE( 86), Y_SCALE( 0));
    E.change_pos( X_SCALE(100), Y_SCALE(32));
    S.change_pos( X_SCALE( 80), Y_SCALE(42));
    W.change_pos( X_SCALE(  0), Y_SCALE(32));
    NW.change_pos(X_SCALE( 18), Y_SCALE(18));
    NE.change_pos(X_SCALE(100), Y_SCALE(18));
    SW.change_pos(X_SCALE( 24), Y_SCALE(43));
    SE.change_pos(X_SCALE(100), Y_SCALE(43));
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
