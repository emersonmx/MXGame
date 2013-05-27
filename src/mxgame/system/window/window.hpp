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

#ifndef MXGAME_SYSTEM_WINDOW_WINDOW_HPP_
#define MXGAME_SYSTEM_WINDOW_WINDOW_HPP_

#include <cstdlib>
#include <string>
#include <list>

#include "mxgame/system/window/window_listener.hpp"

namespace mxgame {
namespace system {
namespace window {

typedef enum Mode {
    kResizable,
    kFixed,
    kNoFrame,
    kFullscreen
} Mode;

class Window {
    public:
        Window()
            : title_("Window"),
              x_(0), y_(0), width_(100), height_(100),
              mode_(kResizable),
              visible_(false) {}

        virtual ~Window() {}

        inline std::string title() const { return title_; }

        virtual void set_title(const std::string& title) { title_ = title; }

        inline int x() const { return x_; }

        virtual void set_x(int x) { x_ = x; }

        inline int y() const { return y_; }

        virtual void set_y(int y) { y_ = y; }

        inline void position(int& x, int& y) { x = x_; y = y_; }

        virtual void set_position(int x, int y) {
            set_x(x);
            set_y(y);
        }

        inline unsigned int width() const { return width_; }

        virtual void set_width(unsigned int width) { width_ = width; }

        inline unsigned int height() const { return height_; }

        virtual void set_height(unsigned int height) { height_ = height; }

        inline void size(unsigned int& width, unsigned int& height) {
            width = width_;
            height = height_;
        }

        virtual void set_size(unsigned int width, unsigned int height) {
            width_ = width;
            height_ = height;
        }

        inline Mode mode() const { return mode_; }

        virtual void set_mode(Mode mode) { mode_ = mode; }

        inline bool visible() const { return visible_; }

        virtual void set_visible(bool visible) { visible_ = visible; }

        virtual void custom_attribute(const std::string& name, void* data) = 0;

        void AddWindowListener(WindowListener* listener) {
            if (listener != NULL) {
                listeners_.push_back(listener);
            }
        }

        void RemoveWindowListener(WindowListener* listener) {
            if (listener != NULL) {
                listeners_.remove(listener);
            }
        }

        virtual void Create(const std::string& name,
                            unsigned int width, unsigned int height,
                            Mode mode,
                            const NamedValuePairList& miscellaneous) {

            set_title(name);
            set_size(width, height);
            set_mode(mode);
            custom_attributes_ = custom_attributes;
        }

        virtual std::size_t handle() const = 0;

        virtual void ProcessEvents() = 0;

        virtual void SwapBuffers(bool wait_vsync=true) = 0;

        virtual void Destroy() = 0;

    protected:
        void FireWindowMoved() {
            for (WindowListenerList::iterator it = listeners_.begin();
                    it != listeners_.end(); ++it) {

                (*it)->Moved(this);
            }
        }

        void FireWindowResized() {
            for (WindowListenerList::iterator it = listeners_.begin();
                    it != listeners_.end(); ++it) {

                (*it)->Resized(this);
            }
        }

        void FireWindowClosed() {
            for (WindowListenerList::iterator it = listeners_.begin();
                    it != listeners_.end(); ++it) {

                (*it)->Closed(this);
            }
        }

        void FireWindowFocusChange() {
            for (WindowListenerList::iterator it = listeners_.begin();
                    it != listeners_.end(); ++it) {

                (*it)->FocusChange(this);
            }
        }

    private:
        typedef std::map<std::string, std::string> NamedValuePairList;
        typedef std::list<WindowListener*> WindowListenerList;

        WindowListenerList listeners_;

        std::string title_;

        int x_;
        int y_;
        unsigned int width_;
        unsigned int height_;
        Mode mode_;
        bool visible_;
};

} /* namespace window */
} /* namespace system */
} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_WINDOW_WINDOW_HPP_ */

