#ifndef STARFORGE_PARTICLE_SYSTEM_H
#define STARFORGE_PARTICLE_SYSTEM_H

#include "starforge_particle.h"
#include "starforge_world.h"
#include "starforge_emitter.h"

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

void starforge_particlesystem_set_emitter(
    StarforgeParticleSystem* system,
    StarforgeEmitter* emitter
);

void starforge_particlesystem_emit_single(
    StarforgeParticleSystem* system,
    float x,
    float y,
    float vx,
    float vy
);

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_PARTICLE_SYSTEM_H */
