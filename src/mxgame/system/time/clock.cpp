#include "mxgame/system/time/clock.hpp"

namespace mxgame {
namespace Time {

unsigned Clock::Ticks(unsigned framerate) {
    if (framerate == 0) {
        framerate = 1;
    }

    time_ = 1000.f / framerate;

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
