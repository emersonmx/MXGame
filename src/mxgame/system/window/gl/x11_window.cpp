/*
  Copyright (C) 2013 Emerson Max de Medeiros Silva

  This file is part of mxgame.

  mxgame is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  mxgame is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with mxgame.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cstdlib>

#include "mxgame/system/window/window_exception.hpp"

#include "mxgame/system/window/gl/x11_window.hpp"

namespace mxgame {
namespace system {
namespace window {

X11Window::X11Window()
        : display_(NULL), visual_info_(NULL), fbconfig_(NULL), context_(NULL) {

    attributes_.push_back(GLX_RENDER_TYPE);
    attributes_.push_back(GLX_RGBA_BIT);
    attributes_.push_back(GLX_X_RENDERABLE);
    attributes_.push_back(true);
    attributes_.push_back(GLX_DRAWABLE_TYPE);
    attributes_.push_back(GLX_WINDOW_BIT);
    attributes_.push_back(GLX_DOUBLEBUFFER);
    attributes_.push_back(true);
    attributes_.push_back(GLX_RED_SIZE);
    attributes_.push_back(8);
    attributes_.push_back(GLX_GREEN_SIZE);
    attributes_.push_back(8);
    attributes_.push_back(GLX_BLUE_SIZE);
    attributes_.push_back(8);
    attributes_.push_back(None);
}

void X11Window::Open() {
    SetupDisplay();
    CheckGLXVersion();
    ChooseFBConfig();
    SetupVisualInfo();
    SetupWindowAttributes();
    SetupWindow();
    SetupGLXContext();

    XSync(display_, false);
}

std::size_t X11Window::handle() const {
    return static_cast<std::size_t>(window_);
}

void X11Window::ProcessEvents() {
    while(XPending(display_)) {
        XNextEvent(display_, &event_);
        switch(event_.type) {
            case ConfigureNotify:
                if (event_.xconfigure.width != width_ ||
                        event_.xconfigure.height != height_) {
                    set_size(event_.xconfigure.width, event_.xconfigure.height);

                    FireWindowResized();
                }
                break;

            case ClientMessage:
                FireWindowClosed();
                break;
        }
    }

}

void X11Window::SwapBuffers() {
    glXSwapBuffers(display_, window_);
}

void X11Window::Close() {
    XUnmapWindow(display_, window_);
    XDestroyWindow(display_, window_);

    if (fbconfig_ != NULL) {
        XFree(fbconfig_);
    }

    if (visual_info_ != NULL) {
        XFree(visual_info_);
    }

    XSync(display_, false);
    XCloseDisplay(display_);
}

void X11Window::SetupDisplay() {
    display_ = XOpenDisplay(getenv("DISPLAY"));
    if (display_ == NULL) {
        throw WindowException("Can't create the display.");
    }
}

void X11Window::CheckGLXVersion() {
    int major_version, minor_version;
    bool query_version = glXQueryVersion(display_, &major_version,
                                         &minor_version);
    if (!query_version) {
        Close();
        throw WindowException("Failed to query version.");
    }

    if (major_version == 1 && minor_version < 3) {
        Close();
        throw WindowException(
            "Require GLX >= 1.3. GLX system version.");
    }
}

void X11Window::ChooseFBConfig() {
    int n_configs = 0;
    fbconfig_ = glXChooseFBConfig(display_, DefaultScreen(display_),
                                  &attributes_.at(0), &n_configs);
    if (fbconfig_ == NULL) {
        Close();
        throw WindowException("Couldn't choose a FBConfig.");
    }
}

void X11Window::SetupVisualInfo() {
    visual_info_ = glXGetVisualFromFBConfig(display_, fbconfig_[0]);
    if (visual_info_ == NULL) {
        Close();
        throw WindowException("Couldn't choose a FBConfig.");
    }
}

void X11Window::SetupWindowAttributes() {
    window_attributes_.event_mask = ExposureMask | VisibilityChangeMask |
                                    StructureNotifyMask;
    window_attributes_.border_pixel = 0;
    window_attributes_.bit_gravity = StaticGravity;
    window_attributes_.colormap = XCreateColormap(display_,
            RootWindow(display_, visual_info_->screen),
            visual_info_->visual, AllocNone);

    window_mask_ = CWBorderPixel | CWBitGravity | CWEventMask | CWColormap;
}

void X11Window::SetupWindow() {
    window_ = XCreateWindow(display_, DefaultRootWindow(display_),
            x_, y_, width_, height_, 0,
            visual_info_->depth, InputOutput,
            visual_info_->visual, window_mask_, &window_attributes_);

    Atom delete_event = XInternAtom(display_, "WM_DELETE_WINDOW", true);
    XSetWMProtocols(display_, window_, &delete_event, 1);

    XMapWindow(display_, window_);
    XRaiseWindow(display_, window_);
}

void X11Window::SetupGLXContext() {
    context_ = glXCreateContext(display_, visual_info_, NULL, true);
    if (context_ == NULL) {
        Close();
        throw WindowException("Couldn't create a GLXContext.");
    }

    glXMakeCurrent(display_, window_, context_);
}

} /* namespace window */
} /* namespace system */
} /* namespace mxgame */

