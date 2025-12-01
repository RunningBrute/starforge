#ifndef STARFORGE_PARTICLE_SYSTEM_H
#define STARFORGE_PARTICLE_SYSTEM_H

#include "starforge_particle.h"
#include "starforge_world.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeParticleSystem StarforgeParticleSystem;

/* Creation */
StarforgeParticleSystem* starforge_particlesystem_create(
    StarforgeParticle* pool,
    int max_particles
);

/*  Destruction */
void starforge_particlesystem_destroy(StarforgeParticleSystem* system);

/* Emission control */
void starforge_particlesystem_emit_rain(
    StarforgeParticleSystem* system,
    float x_min,
    float x_max,
    int count
);

/* Update all particles using global world forces */
void starforge_particlesystem_update(
    StarforgeParticleSystem* system,
    const StarforgeWorldForces* world,
    float dt
);

/* Access to live particles for rendering */
const StarforgeParticle* starforge_particlesystem_particles(
    const StarforgeParticleSystem* system,
    int* out_count
);

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_SYSTEM_H */
