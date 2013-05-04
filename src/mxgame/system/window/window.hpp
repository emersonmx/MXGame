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
            : title_("MXGame Window"),
              x_(0), y_(0), width_(100), height_(100),
              mode_(kResizable) {}

        virtual ~Window() {}

        inline std::string title() const { return title_; }

        inline void set_title(const std::string& title) { title_ = title; }

        inline int x() const { return x_; }

        inline void set_x(int x) { x_ = x; }

        inline int y() const { return y_; }

        inline void set_y(int y) { y_ = y; }

        inline void position(int& x, int& y) { x = x_; y = y_; }

        inline void set_position(int x, int y) {
            set_x(x);
            set_y(y);
        }

        inline int width() const { return width_; }

        inline void set_width(int width) { width_ = width; }

        inline int height() const { return height_; }

        inline void set_height(int height) { height_ = height; }

        void size(int& width, int& height) {
            width = width_;
            height = height_;
        }

        void set_size(int width, int height) {
            set_width(width);
            set_height(height);
        }

        inline Mode mode() const { return mode_; }

        inline void set_mode(Mode mode) { mode_ = mode; }

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

        virtual void Open() = 0;

        virtual std::size_t handle() const = 0;

        virtual void ProcessEvents() = 0;

        virtual void SwapBuffers() = 0;

        virtual void Close() = 0;

    protected:
        virtual void FireWindowShow() {
            for (WindowListenerList::iterator it = listeners_.begin();
                    it != listeners_.end(); ++it) {

                (*it)->Show();
            }

        }
        virtual void FireWindowHide() {
            for (WindowListenerList::iterator it = listeners_.begin();
                    it != listeners_.end(); ++it) {

                (*it)->Hide();
            }
        }

        void FireWindowClosed() {
            for (WindowListenerList::iterator it = listeners_.begin();
                    it != listeners_.end(); ++it) {

                (*it)->Closed();
            }
        }

        void FireWindowResized() {
            for (WindowListenerList::iterator it = listeners_.begin();
                    it != listeners_.end(); ++it) {

                (*it)->Resized(width_, height_);
            }
        }

        std::string title_;

        int x_;
        int y_;
        int width_;
        int height_;
        Mode mode_;

    private:
        typedef std::list<WindowListener*> WindowListenerList;

        WindowListenerList listeners_;
};

} /* namespace window */
} /* namespace system */
} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_WINDOW_WINDOW_HPP_ */

