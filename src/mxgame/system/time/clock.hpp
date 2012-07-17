#ifndef MXGAME_SYSTEM_TIME_CLOCK_H_
#define MXGAME_SYSTEM_TIME_CLOCK_H_

#include "mxgame/system/time/time.hpp"

namespace mxgame {
namespace Time {

class Clock {
    public:
        Clock() : time_(0), last_ticks_(GetTicks()) {}

        inline unsigned time() const { return time_; }
        unsigned Ticks(unsigned framerate);

    private:
        unsigned time_;
        unsigned last_ticks_;
};

} /* namespace Time */
} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_TIME_CLOCK_H_ */
