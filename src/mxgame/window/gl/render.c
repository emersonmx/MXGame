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
#include <GL/glx.h>
#include <mxgame/window/linux/render.h>

mxgame_render* mxgame_render_create(mxgame_window_descriptor* descriptor,
                                    int* attributes)
{
    mxgame_render* render = malloc(sizeof(mxgame_render));
    if (render != NULL)
    {
        if (attributes == NULL)
        {
            static int attr[] = {
                GLX_RGBA,
                GLX_DOUBLEBUFFER,
                GLX_RED_SIZE, 8,
                GLX_GREEN_SIZE, 8,
                GLX_BLUE_SIZE, 8,
                0
            };
            attributes = attr;
        }

        render->attributes = attributes;

        render->display = XOpenDisplay(NULL);
        render->visual_info = glXChooseVisual(render->display,
                                              DefaultScreen(render->display),
                                              render->attributes);

        render->window_attributes.event_mask =
            ExposureMask | VisibilityChangeMask |
            KeyPressMask | PointerMotionMask |
            StructureNotifyMask;
        render->window_attributes.border_pixel = 0;
        render->window_attributes.bit_gravity = StaticGravity;
        render->window_mask = CWBorderPixel | CWBitGravity |
                              CWEventMask | CWColormap;

        render->window_attributes.colormap =
            XCreateColormap(render->display,
                            RootWindow(render->display,
                                       render->visual_info->screen),
                            render->visual_info->visual,
                            AllocNone);

        render->window = XCreateWindow(render->display,
                                       DefaultRootWindow(render->display),
                                       descriptor->x,
                                       descriptor->y,
                                       descriptor->width,
                                       descriptor->height,
                                       0,
                                       descriptor->depth,
                                       InputOutput,
                                       render->visual_info->visual,
                                       render->window_mask,
                                       &(render->window_attributes));

        XStoreName(render->display, render->window, descriptor->caption);

        XMapWindow(render->display, render->window);

        render->context = glXCreateContext(render->display,
                                           render->visual_info,
                                           0,
                                           true);
        glXMakeCurrent(render->display, render->window, render->context);
    }

    return render;
}

void mxgame_render_destroy(mxgame_render* render)
{
    glXMakeCurrent(render->display, None, NULL);
    glXDestroyContext(render->display, render->context);
    render->window = (Window) NULL;
    XCloseDisplay(render->display);
    render->display = NULL;
    free(render);
}

int* mxgame_render_attributes(mxgame_render* render)
{
    return render->attributes;
}

