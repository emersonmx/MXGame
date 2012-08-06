#ifndef MXGAME_SYSTEM_WINDOW_WINDOW_HPP_
#define MXGAME_SYSTEM_WINDOW_WINDOW_HPP_

#include <sstream>

namespace mxgame {

class Window {
    public:
        class Callback {
            public:
                void resize(int width, int height) {}
        };

        class RenderContext {
            public:
                virtual ~RenderContext() {}
                virtual bool Initialize() = 0;
                virtual bool SwapBuffers() = 0;
                virtual void Finalize() = 0;
        };

        static const int kFullScreen = 1;
        static const int kWindow = 2;

        static Window* instance();

        void Create(int width, int heigth, int depth,
                    int mode, RenderContext* render_context);
        void SwapBuffers();
        void Destroy();

        std::string title() const { return title_; }
        void set_title(const std::string& title) { title_ = title; }
        void* icon() { return icon_; }
        void set_icon(void* icon) { icon_ = icon; }

        int x() const { return x_; }
        void set_x(int x) { x_ = x; }
        int y() const { return y_; }
        void set_y(int y) { y_ = y; }
        int width() const { return width_; }
        void set_width(int width);
        int height() const { return height_; }
        void set_height(int height);
        int depth() const { return depth_; }
        int mode() const { return mode_; }

        RenderContext* render_context() { return render_context_; }
        Callback* callback() { return callback_; }
        void set_callback(Callback* callback) { callback_ = callback; }

    private:
        Window();

        static Window* instance_;

        std::string title_;
        void* icon_;

        int x_;
        int y_;
        int width_;
        int height_;
        int depth_;
        int mode_;

        RenderContext* render_context_;
        Callback* callback_;
};

} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_WINDOW_WINDOW_HPP_ */
