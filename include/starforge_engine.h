#ifndef STARFORGE_ENGINE_H
#define STARFORGE_ENGINE_H

#include "starforge_world.h"
#include "starforge_particlesystem.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeEngine StarforgeEngine;

StarforgeEngine* starforge_engine_create(
    StarforgeParticle* global_pool,
    int max_particles,
    int max_systems
);

void starforge_engine_destroy(StarforgeEngine* engine);

/* Access to global world */
StarforgeWorldForces* starforge_engine_world(StarforgeEngine* engine);

/* Create new particle system inside engine */
StarforgeParticleSystem* starforge_engine_create_system(
    StarforgeEngine* engine
);

/* Global update of all systems */
void starforge_engine_update(StarforgeEngine* engine, float dt);

const StarforgeParticle* starforge_engine_particles(
    const StarforgeEngine* engine,
    int* out_count
);

#ifdef __cplusplus
}
#endif

#endif
