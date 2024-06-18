#pragma once

#include "def.h"
#include "level.h"

SDL_Event event;

void rotate_view(float radians)
{
    direction.x = direction.x * cosf(radians) - direction.y * sinf(radians);
    direction.y = direction.x * sinf(radians) + direction.y * cosf(radians);

    plane.x = plane.x * cosf(radians) - plane.y * sinf(radians);
    plane.y = plane.x * sinf(radians) + plane.y * cosf(radians);
}

void input()
{
    const uint8_t *key = SDL_GetKeyboardState(NULL);

    float dx = direction.x * delta_tick;
    float dy = direction.y * delta_tick;

    // step forward
    if (key[SDL_SCANCODE_W])
    {
        view.x += dx * (key[SDL_SCANCODE_LSHIFT] ? SPRINT_SPEED : SPEED);
        view.y += dy * (key[SDL_SCANCODE_LSHIFT] ? SPRINT_SPEED : SPEED);
    }

    // step backward
    if (key[SDL_SCANCODE_S])
    {
        view.x -= dx * (key[SDL_SCANCODE_LSHIFT] ? SPRINT_SPEED : SPEED);
        view.y -= dy * (key[SDL_SCANCODE_LSHIFT] ? SPRINT_SPEED : SPEED);
    }

    // strafe left
    if (key[SDL_SCANCODE_A])
    {
        view.x -= dy * (key[SDL_SCANCODE_LSHIFT] ? SPRINT_SPEED : SPEED);
        view.y += dx * (key[SDL_SCANCODE_LSHIFT] ? SPRINT_SPEED : SPEED);
    }

    // strafe right
    if (key[SDL_SCANCODE_D])
    {
        view.x += dy * (key[SDL_SCANCODE_LSHIFT] ? SPRINT_SPEED : SPEED);
        view.y -= dx * (key[SDL_SCANCODE_LSHIFT] ? SPRINT_SPEED : SPEED);
    }
    
    // rotate left
    if (key[SDL_SCANCODE_LEFT])
    {
        rotate_view(SENSITIVITY * delta_tick);
    }

    // rotate right
    if (key[SDL_SCANCODE_RIGHT])
    {
        rotate_view(-SENSITIVITY * delta_tick);
    }

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: SDL_Quit(); exit(0);
                }
            break;

            case SDL_QUIT: SDL_Quit(); exit(0);
        }
    }
}