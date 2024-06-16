#pragma once

#include "def.h"

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