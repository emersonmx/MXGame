#include "mxgame/system/window/window.hpp"

using namespace std;

namespace mxgame {

Window* Window::instance_ = NULL;
Window::Callback null_callback;

Window::Window()
    : title_("Simple Window"), icon_(NULL), x_(0), y_(0),
      width_(640), height_(480), depth_(24), mode_(kWindow),
      render_context_(NULL), callback_(&null_callback) {}

void Window::Create(int width, int heigth, int depth,
                    int mode, RenderContext* render_context) {
    width_ = width;
    height_ = heigth;
    depth_ = depth;
    mode_ = mode;
    render_context_ = render_context;

    render_context_->Initialize();
}

void Window::SwapBuffers() {
    render_context_->SwapBuffers();
}

void Window::Destroy() {
    render_context_->Finalize();
}

Window* Window::instance() {
    if (instance_ == NULL) {
        instance_ = new Window();
    }

    return instance_;
}

void Window::set_width(int width) {
    width_ = width;
    callback_->resize(width_, height_);
}

void Window::set_height(int height) {
    height_ = height;
    callback_->resize(width_, height_);
}

} /* namespace mxgame */
