#include <stdio.h>

#include "starforge_engine.h"

#define MAX_PARTICLES 2000
#define MAX_SYSTEMS   4

int main(void)
{
    static StarforgeParticle pool[MAX_PARTICLES];

    StarforgeEngine* engine =
        starforge_engine_create(pool, MAX_PARTICLES, MAX_SYSTEMS);
        
    starforge_engine_destroy(engine);
    return 0;
}
