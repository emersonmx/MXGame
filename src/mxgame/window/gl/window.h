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

#ifndef _MXGAME_GL_WINDOW_H
#define _MXGAME_GL_WINDOW_H

#include <stdbool.h>

typedef enum mxgame_gl_attribute_e
{
    MXGAME_GL_RED_SIZE,
    MXGAME_GL_GREEN_SIZE,
    MXGAME_GL_BLUE_SIZE,
    MXGAME_GL_ALPHA_SIZE,
    MXGAME_GL_DOUBLE_BUFFER,
    MXGAME_GL_BUFFER_SIZE,
    MXGAME_GL_DEPTH_SIZE,
    MXGAME_GL_STENCIL_SIZE,
    MXGAME_GL_ACCUM_RED_SIZE,
    MXGAME_GL_ACCUM_GREEN_SIZE,
    MXGAME_GL_ACCUM_BLUE_SIZE,
    MXGAME_GL_ACCUM_ALPHA_SIZE,
    MXGAME_GL_ATTRIBUTE_SIZE
} mxgame_gl_attribute;

typedef struct mxgame_gl_window_t mxgame_gl_window;

mxgame_gl_window* mxgame_gl_window_create(int width,
                                          int height,
                                          int depth,
                                          bool fullscreen,
                                          bool double_buffer,
                                          int* attributes);
void mxgame_gl_window_destroy(mxgame_gl_window* window);

void mxgame_gl_window_set_caption(mxgame_gl_window* window,
                                  const char* caption);
void mxgame_gl_window_set_icon(mxgame_gl_window* window, void* data);
void mxgame_gl_window_set_position(mxgame_gl_window* window, int x, int y);
void mxgame_gl_window_set_size(mxgame_gl_window* window,
                               unsigned int width,
                               unsigned int height);
void mxgame_gl_window_set_depth(mxgame_gl_window* window, unsigned int depth);
void mxgame_gl_window_set_fullscreen(mxgame_gl_window* window, bool fullscreen);
void mxgame_gl_window_set_double_buffer(mxgame_gl_window* window,
                                        bool double_buffer);
void mxgame_gl_window_set_attribute(mxgame_gl_window* window,
                                    mxgame_gl_attribute attribute,
                                    int value);

#endif /* _MXGAME_GL_WINDOW_H */

