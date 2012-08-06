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

#include <stdlib.h>
#include <mxgame/window/gl_window.h>

struct mxgame_gl_window_t
{
    Window root;
    Window window;
    GLint window_mask;
    Display* display;
    int screen;

    XVisualInfo* visual_info;
    Colormap color_map;
    XSetWindowAttributes window_attributes;
    XF86VidModeModeInfo desktop_mode;

    GLXFBConfig* fb_configs;
    GLXWindow glx_window;
    GLXContext context;
    int* attributes;
};


    bool fullscreen;
    bool double_buffer;
};

mxgame_gl_window_descriptor* mxgame_gl_window_descriptor_create()
{
    mxgame_gl_window_descriptor* descriptor =
        malloc(sizeof(mxgame_gl_window_descriptor));

    if (descriptor != NULL)
    {
        descriptor->caption = NULL;
        descriptor->icon = NULL;
        descriptor->x = 0;
        descriptor->y = 0;
        descriptor->width = 640;
        descriptor->height = 480;
        descriptor->depth = 24;
        descriptor->fullscreen = false;
        descriptor->double_buffer = true;
    }

    return descriptor;
}

void mxgame_gl_window_descriptor_destroy(mxgame_gl_window_descriptor* descriptor)
{
    free(descriptor);
}

mxgame_gl_window* mxgame_gl_window_create(unsigned int width,
                                    unsigned int height,
                                    unsigned int depth,
                                    unsigned int flags)
{

}

void mxgame_gl_window_destroy(mxgame_gl_window* window)
{

}

