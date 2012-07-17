#include <cstdlib>
#include <sys/time.h>
#include <unistd.h>
#include "mxgame/system/time/time.hpp"

namespace mxgame {
namespace Time {

static struct timeval StartTime() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return now;
}

static struct timeval start_time = StartTime();

unsigned GetTicks() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return (now.tv_sec - start_time.tv_sec) * 1000 +
           (now.tv_usec - start_time.tv_usec) / 1000;
}

void Delay(unsigned milliseconds) {
    usleep(milliseconds * 1000);
}

} /* namespace Time */
} /* namespace mxgame */
