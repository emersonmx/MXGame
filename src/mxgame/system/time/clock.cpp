#include "mxgame/system/time/clock.hpp"

namespace mxgame {
namespace Time {

unsigned Clock::Ticks() {
    if (framerate_ == 0) {
        framerate_ = 1;
    }

    time_ = 1000.f / framerate_;

    unsigned delta = GetTicks() - last_ticks_;

    if (delta < time_) {
        Delay(time_ - delta);
    } else {
        time_ = delta;
    }

    last_ticks_ = GetTicks();

    return time_;
}

} /* namespace Time */
} /* namespace mxgame */

