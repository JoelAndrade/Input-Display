#ifndef COMMON_H
#define COMMON_H

#include <cmath>

#define SCALE(input) (input * (double)(window->h/280.0))
#define X_SCALE(default_pos) ((int)(std::round((default_pos*window->w)/840.0)))
#define Y_SCALE(default_pos) ((int)(std::round((default_pos*window->h)/280.0)))

#endif // COMMON_H

