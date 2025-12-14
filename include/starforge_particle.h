#ifndef STARFORGE_PARTICLE_H
#define STARFORGE_PARTICLE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    STARFORGE_PARTICLE_RAIN = 0,
    STARFORGE_PARTICLE_FIRE,
    STARFORGE_PARTICLE_SMOKE,
    STARFORGE_PARTICLE_SPARK
} StarforgeParticleType;

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
