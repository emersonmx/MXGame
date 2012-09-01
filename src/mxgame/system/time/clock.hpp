#ifndef MXGAME_SYSTEM_TIME_CLOCK_HPP_
#define MXGAME_SYSTEM_TIME_CLOCK_HPP_

#include "mxgame/system/time/time.hpp"

namespace mxgame {
namespace Time {

class Clock {
    public:
        static const unsigned DEFAULT_FRAMERATE = 30;

        Clock(unsigned framerate=DEFAULT_FRAMERATE)
                : time_(0), last_ticks_(GetTicks()), framerate_(framerate) {}

        inline unsigned time() const { return time_; }
        inline unsigned framerate() const { return framerate_; }
        inline void set_framerate(unsigned framerate) {
            framerate_ = framerate;
        }

        unsigned Ticks();

    private:
        unsigned time_;
        unsigned last_ticks_;

        unsigned framerate_;
};

} /* namespace Time */
} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_TIME_CLOCK_HPP_ */

