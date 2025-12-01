#ifndef STARFORGE_WORLD_H
#define STARFORGE_WORLD_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    float gravity_x;
    float gravity_y;

    float wind_x;
    float wind_y;

    float drag;
    float turbulence;
} StarforgeWorldForces;

/* Initialize default world forces */
void starforge_world_init(StarforgeWorldForces* world);

/* Setters */
void starforge_world_set_gravity(StarforgeWorldForces* world, float gx, float gy);
void starforge_world_set_wind(StarforgeWorldForces* world, float wx, float wy);
void starforge_world_set_drag(StarforgeWorldForces* world, float drag);
void starforge_world_set_turbulence(StarforgeWorldForces* world, float turbulence);

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_WORLD_H */
