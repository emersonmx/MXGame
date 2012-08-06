#ifndef MXGAME_WINDOW_RENDER_CONTEXT_HPP_
#define MXGAME_WINDOW_RENDER_CONTEXT_HPP_

namespace mxgame {

class RenderContext {
    public:
        virtual ~RenderContext() {}
        virtual bool Initialize() = 0;
        virtual void Finalize() = 0;
};

} /* namespace mxgame */
#endif /* MXGAME_WINDOW_RENDER_CONTEXT_HPP_ */
