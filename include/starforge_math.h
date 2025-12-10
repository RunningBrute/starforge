#ifndef STARFORGE_MATH_H
#define STARFORGE_MATH_H

#include <stdlib.h>

static inline float frand(float min, float max)
{
    return min + (float)rand() / (float)RAND_MAX * (max - min);
}

#endif
