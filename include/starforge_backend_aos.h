#ifndef STARFORGE_BACKEND_AOS_H
#define STARFORCE_BACKEND_AOS_H

#include "starforge_backend.h"

#ifdef __cplusplus
extern "C" {
#endif

struct StarforgeParticleSystem;

StarforgeBackend* starforge_backend_aos_create(
    StarforgeParticleSystem* system)

#ifdef __cplusplus
}
#endif

#endif
