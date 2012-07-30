#include <boost/chrono.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "mxgame/system/time/time.hpp"

namespace mxgame {
namespace Time {

using namespace boost;

typedef chrono::duration<unsigned, milli> milliseconds;

static asio::io_service io;
static asio::deadline_timer timer(io);
static chrono::steady_clock::time_point start(chrono::steady_clock::now());

unsigned GetTicks() {
    milliseconds ms =
        chrono::round<milliseconds>(chrono::steady_clock::now() - start);
    return ms.count();
}

void Delay(unsigned milliseconds) {
    timer.expires_from_now(posix_time::milliseconds(milliseconds));
    timer.wait();
}

} /* namespace Time */
} /* namespace mxgame */

