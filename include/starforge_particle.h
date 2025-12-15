#ifndef STARFORGE_PARTICLE_H
#define STARFORGE_PARTICLE_H

#include "starforge_particle_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    float x, y;        /* Position */
    float vx, vy;      /* Velocity */

    float life;        /* Current life */
    float max_life;    /* Lifetime */

    float size;        /* Visual size */

    float r, g, b, a;  /* Color (RGBA) */

    StarforgeParticleType type;

    int alive;
} StarforgeParticle;

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_H */
