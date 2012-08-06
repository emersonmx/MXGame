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

#ifndef _MXGAME__H
#define _MXGAME_RENDER_H

#include <mxgame/window/window.h>

typedef struct mxgame_render_t
{
    Window root;
    Window window;
    GLint window_mask;
    Display* display;
    int screen;

    XVisualInfo* visual_info;
    Colormap color_map;
    XSetWindowAttributes window_attributes;
    //XF86VidModeModeInfo desktop_mode;

    GLXFBConfig* fb_configs;
    GLXWindow glx_window;
    GLXContext context;
    int* attributes;
} mxgame_render;

mxgame_render* mxgame_render_create(mxgame_window_descriptor* descriptor,
                                    int* attributes);
void mxgame_render_destroy(mxgame_render* render);

inline int* mxgame_render_attributes(mxgame_render* render);

#endif /* _MXGAME_RENDER_H */
