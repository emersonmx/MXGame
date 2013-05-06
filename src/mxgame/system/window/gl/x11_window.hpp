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

#ifndef MXGAME_SYSTEM_WINDOW_GL_X11_WINDOW_HPP_
#define MXGAME_SYSTEM_WINDOW_GL_X11_WINDOW_HPP_

#include <GL/glx.h>
#include <string>
#include <vector>

#include "mxgame/system/window/window.hpp"

typedef Window XWindow;

namespace mxgame {
namespace system {
namespace window {

class X11Window : public Window {
    public:
        typedef std::vector<int> AttributeArray;

        X11Window();

        inline AttributeArray attributes() const { return attributes_; }

        inline void set_attributes(const AttributeArray& attributes) {
            attributes_ = attributes;
        }

        virtual void Open();

        virtual std::size_t handle() const;

        virtual void ProcessEvents();

        virtual void SwapBuffers();

        virtual void Close();

    private:
        void SetupDisplay();

        void CheckGLXVersion();

        void ChooseFBConfig();

        void SetupVisualInfo();

        void SetupWindowAttributes();

        void SetupWindow();

        void SetupGLXContext();

        XWindow window_;
        XSetWindowAttributes window_attributes_;
        GLint window_mask_;
        XEvent event_;

        Display* display_;
        XVisualInfo* visual_info_;

        GLXFBConfig* fbconfig_;
        GLXContext context_;

        AttributeArray attributes_;
};

} /* namespace window */
} /* namespace system */
} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_WINDOW_GL_X11_WINDOW_HPP_ */

