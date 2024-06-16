#pragma once

#include "screen.h"

void render_line(int x, int y0, int y1, uint32_t color)
{
    for (int y = y0; y <= y1; y++)
    {
        color_buffer[x + y * WIDTH] = color;
    }
}