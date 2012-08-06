#include <stdio.h>
#include <unistd.h>
#include <GL/glx.h>
#include <mxgame/window/window.h>
#include <mxgame/window/render.h>

int main()
{
    mxgame_window_descriptor* descriptor = mxgame_window_descriptor_create();
    mxgame_render* render = NULL;
    int attr[] = {
        GLX_RGBA,
        GLX_DOUBLEBUFFER,
        GLX_RED_SIZE, 8,
        GLX_GREEN_SIZE, 8,
        GLX_BLUE_SIZE, 8,
        0
    };

    descriptor->caption = "Haduken!";
    descriptor->x = 100;
    descriptor->y = 100;
    mxgame_render_create(descriptor, NULL/*attr*/);

    sleep(3);

    mxgame_render_destroy(render);
    mxgame_window_descriptor_destroy(descriptor);

    return 0;
}

