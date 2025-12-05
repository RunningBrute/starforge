#ifndef STARFORGE_BACKEND_AOS_H
#define STARFORGE_BACKEND_AOS_H

#include "starforge_backend.h"
#include "starforge_particlesystem.h"

#ifdef __cplusplus
extern "C" {
#endif

StarforgeBackend* starforge_backend_aos_create(
    StarforgeParticleSystem* system);

#ifdef __cplusplus
}
#endif

#endif
