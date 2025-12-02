#ifndef STARFORGE_FRONTEND_H
#define STARFORGE_FRONTEND_H

typedef struct StarforgeEngine StarforgeEngine;

#ifdef __cplusplus
extern "C" {
#endif

typedef struct StarforgeFrontend StarforgeFrontend;

struct StarforgeFrontend
{
    void (*init)(StarforgeFrontend* self);
    void (*render)(
        StarforgeFrontend* self,
	const StarforgeEngine* engine
    );
    void (*shutdown)(StarforgeFrontend* self);

    void* context;
};

#ifdef __cplusplus
}
#endif

#endif
