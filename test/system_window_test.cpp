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

#include <cstdio>

#include "mxgame/application/application.hpp"
#include "mxgame/system/window/gl/x11_window.hpp"

using namespace mxgame;

class WindowApplication : public application::Application,
                          public system::window::WindowListener {
    public:
        virtual void Initialize(){
            window_ = new system::window::X11Window();
            window_->set_size(640, 480);
            window_->AddWindowListener(this);

            window_->Open();

            glViewport(0, 0, window_->width(), window_->height());
            glClearColor(0, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
        }

        virtual void Update(){
            window_->ProcessEvents();
        }

        virtual void Render(){
            glClear(GL_COLOR_BUFFER_BIT);

            glBegin(GL_TRIANGLES);
                glVertex2f(0.0f, 1.0f);
                glVertex2f(-1.0f, -1.0f);
                glVertex2f(1.0f, -1.0f);
            glEnd();

            window_->SwapBuffers();
        }

        virtual void Finalize() throw(){
            window_->Close();

            delete window_;
        }

        virtual void Closed() {
            printf("Exit\n");
            Exit(0);
        }

        virtual void Resized(int width, int height) {
            printf("Resize %d, %d\n", width, height);
        }

    private:
        system::window::Window* window_;
};

int main() {
    application::Application* application = new WindowApplication();

    application->Run();

    return application->error_code();
}

