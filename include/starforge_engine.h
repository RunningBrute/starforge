#ifndef STARFORGE_ENGINE_H
#define STARFORGE_ENGINE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeEngine StarforgeEngine;

/* Create engine instance */
StarforgeEngine* starforge_engine_create(void);

/* Single simulation step */
void starforge_engine_update(StarforgeEngine* engine);

/* Destroy engine instance */
void starforge_engine_destroy(StarforgeEngine* engine);

#ifdef __cplusplus
}
#endif

#endif /* STARFORGE_ENGINE_H */
