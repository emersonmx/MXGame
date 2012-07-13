#include <cstdlib>
#include <sys/time.h>
#include <unistd.h>

#include "mxgame/system/time/time.hpp"

namespace mxgame {

Time::Time() {
    gettimeofday(&start_time_, NULL);
}

unsigned Time::ticks() const {
    struct timeval now;
    gettimeofday(&now, NULL);
    return (now.tv_sec - start_time_.tv_sec) * 1000 +
           (now.tv_usec - start_time_.tv_usec) / 1000;
}

void Time::Delay(unsigned milliseconds) {
    usleep(milliseconds * 1000);
}

} /* namespace mxgame */
