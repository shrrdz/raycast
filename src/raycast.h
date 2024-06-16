#pragma once

#include "def.h"
#include "level.h"
#include "render.h"
#include "palette.h"

// position of the observer
vector2 view = { 12, 8 };

// direction the observer is looking
vector2 direction = { -1, 0 };

// vector of the view plane
vector2 plane = { 0, ASPECT_RATIO / 2 };

void raycast()
{
    // cast a ray for each screen column
    for (int x = 0; x < WIDTH; x++)
    {
        bool hit = FALSE;

        // x coordinate in camera space
        float camera_x = 2 * x / (float) WIDTH - 1;

        vector2 ray_position  = { view.x, view.y };
        vector2 ray_direction = { direction.x + plane.x * camera_x, direction.y + plane.y * camera_x };

        // distance the ray travels from first side to the next side
        vector2 step =
        {
            ray_direction.x == 0 ? INFINITY : fabs(1 / ray_direction.x),
            ray_direction.y == 0 ? INFINITY : fabs(1 / ray_direction.y)
        };

        // distance the ray travels from its origin to the first side
        vector2 intercept =
        {
            ray_direction.x < 0 ? (view.x - ray_position.x) * step.x : (ray_position.x + 1 - view.x) * step.x,
            ray_direction.y < 0 ? (view.y - ray_position.y) * step.y : (ray_position.y + 1 - view.y) * step.y
        };

        // direction of the ray step
        vector2 tile_step =
        {
            ray_direction.x < 0 ? -1 : 1,
            ray_direction.y < 0 ? -1 : 1
        };

        int side;
        float perpendicular_distance;

        // cast a ray to each block on the grid using DDA until it hits a wall
        while (!hit)
        {
            if (intercept.x < intercept.y)
            {
                // step in x
                intercept.x += step.x;
                ray_position.x += tile_step.x;
                side = SIDE_X;

                perpendicular_distance = (ray_position.x - view.x + (1 - tile_step.x) / 2) / ray_direction.x;
            }
            else
            {
                // step in y
                intercept.y += step.y;
                ray_position.y += tile_step.y;
                side = SIDE_Y;

                perpendicular_distance = (ray_position.y - view.y + (1 - tile_step.y) / 2) / ray_direction.y;
            }

            // the ray has hit a wall
            if (location(ray_position.x, ray_position.y) > 0) hit = TRUE;
        }
        
        // calculate the distance projected on the view
        perpendicular_distance = side == SIDE_X ?
        (ray_position.x - view.x + (1 - tile_step.x) / 2) / ray_direction.x : 
        (ray_position.y - view.y + (1 - tile_step.y) / 2) / ray_direction.y;

        int wall_height = (int) (HEIGHT / perpendicular_distance);

        // starting and ending y-point of a wall
        int y_start = MAX(0, -wall_height / 2 + HEIGHT / 2);
        int y_end   = MIN(wall_height / 2 + HEIGHT / 2, HEIGHT - 1);

        uint32_t wall_color = palette_lookup(location(ray_position.x, ray_position.y));

        // make the y-sided walls darker
        if (side == SIDE_Y) wall_color = (wall_color >> 1) & 0x7F7F7F;

        render_line(x, 0, y_start, DARKGRAY);           // render the ceiling
        render_line(x, y_start, y_end, wall_color);     // render the walls
        render_line(x, y_end, HEIGHT - 1, GRAY);        // render the floor
    }
}