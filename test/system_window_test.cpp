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

        virtual void Show() {
            printf("Show\n");
        }

        virtual void Hide() {
            printf("Hide\n");
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

