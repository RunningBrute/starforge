#include "starforge_frontend_raylib.h"
#include "starforge_engine.h"
#include "raylib.h"

static void raylib_init(StarforgeFrontend* self)
{
    (void)self;
    InitWindow(1000, 700, "StarForge - Raylib");
    SetTargetFPS(60);
}

static void raylib_render(
    StarforgeFrontend* self,
    const StarforgeEngine* engine)
{
    (void)self;

    BeginDrawing();
    ClearBackground(BLACK);

    DrawText("StarForge Raylib running", 20, 20, 20, WHITE);

    int count;
    const StarforgeParticle* particles =
        starforge_engine_particles(engine, &count);

    for (int i = 0; i < count; ++i)
    {
        int screenWidth  = 1000;
        int screenHeight = 700;

        int x = (int)(particles[i].x * 8.0f + screenWidth / 2);
        int y = (int)(screenHeight - (particles[i].y * 8.0f + screenHeight / 2));

        DrawCircle(x, y, 2, SKYBLUE);
    }

    EndDrawing();
}

static void raylib_shutdown(StarforgeFrontend* self)
{
    (void)self;
    CloseWindow();
}

void starforge_frontend_raylib_create(StarforgeFrontend* out_frontend)
{
    out_frontend->init = raylib_init;
    out_frontend->render = raylib_render;
    out_frontend->shutdown = raylib_shutdown;
    out_frontend->context = NULL;
}
