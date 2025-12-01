#include "starforge_world.h"

void starforge_world_init(StarforgeWorldForces* world)
{
    world->gravity_x = 0.0f;
    world->gravity_y = -9.8f;

    world->wind_x = 0.0f;
    world->wind_y = 0.0f;

    world->drag = 0.0f;
    world->turbulence = 0.0f;
}

void starforge_world_set_gravity(StarforgeWorldForces* world, float gx, float gy)
{
    world->gravity_x = gx;
    world->gravity_y = gy;
}

void starforge_world_set_wind(StarforgeWorldForces* world, float wx, float wy)
{
    world->wind_x = wx;
    world->wind_y = wy;
}

void starforge_world_set_drag(StarforgeWorldForces* world, float drag)
{
    world->drag = drag;
}

void starforge_world_set_turbulence(StarforgeWorldForces* world, float turbulence)
{
    world->turbulence = turbulence;
}
