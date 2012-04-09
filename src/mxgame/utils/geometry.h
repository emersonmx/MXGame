/**
 * Copyright 2012 Emerson Max de Medeiros Silva
 *
 * Author: Emerson Max de Medeiros Silva <emersonmx@gmail.com>
 *
 * This file is part of mxgame.
 *
 * mxgame is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mxgame is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mxgame.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MXGAME_GEOMETRY_H
#define _MXGAME_GEOMETRY_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct mxgame_point_t
{
    float x;
    float y;
    float z;
} mxgame_point;

typedef struct mxgame_line_t
{
    mxgame_point start;
    mxgame_point end;
} mxgame_line;

typedef struct mxgame_plane_t
{
    float x;
    float y;
    float z;
    float width;
    float height;
} mxgame_plane;

typedef struct mxgame_sphere_t
{
    mxgame_point center;
    float radius;
} mxgame_sphere;

typedef mxgame_sphere mxgame_circle;
typedef mxgame_plane mxgame_rectangle;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MXGAME_GEOMETRY_H */

