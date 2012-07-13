#ifndef MXGAME_SYSTEM_TIME_HPP_
#define MXGAME_SYSTEM_TIME_HPP_

#include <ctime>

namespace mxgame {

class Time {
    public:
        Time();
        unsigned ticks() const;
        void Delay(unsigned milliseconds);

    private:
        struct timeval start_time_;

};

} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_TIME_HPP_ */
