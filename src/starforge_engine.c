#include "starforge_engine.h"
#include <stdio.h>
#include <stdlib.h>

struct StarforgeEngine
{
    int tick;
};

StarforgeEngine* starforge_engine_create(void)
{
    StarforgeEngine* engine = (StarforgeEngine*)malloc(sizeof(StarforgeEngine));
    if (!engine)
        return NULL;

    engine->tick = 0;

    printf("[StarForge] Engine created\n");
    return engine;
}

void starforge_engine_update(StarforgeEngine* engine)
{
    if (!engine)
        return;

    engine->tick++;
    printf("[StarForge] Tick %d\n", engine->tick);
}

void starforge_engine_destroy(StarforgeEngine* engine)
{
    if (!engine)
        return;

    printf("[StarForge] Engine destroyed at tick %d\n", engine->tick);
    free(engine);
}
