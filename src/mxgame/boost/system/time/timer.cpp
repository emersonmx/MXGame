/*
  Copyright (C) 2012, 2013 Emerson Max de Medeiros Silva

  This file is part of mxgame.

  mxgame is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  mxgame is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with mxgame.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <mxgame/boost/system/time/timer.hpp>

#include <boost/chrono/round.hpp>

namespace mxgame {
namespace boost {
namespace system {
namespace time {

typedef ::boost::chrono::duration<unsigned, ::boost::milli> milliseconds;

Timer::Timer()
        : timer_(io_) {

    Reset();
}

unsigned long Timer::ticks() {
    milliseconds ms =
        ::boost::chrono::round<milliseconds>(
                ::boost::chrono::steady_clock::now() - start_time_);

    return ms.count();
}

void Timer::Reset() {
    start_time_ = ::boost::chrono::steady_clock::now();
}

void Timer::Delay(unsigned long milliseconds) {
    timer_.expires_from_now(::boost::posix_time::milliseconds(milliseconds));
    timer_.wait();
}

} /* namespace time */
} /* namespace system */
} /* namespace boost */
} /* namespace mxgame */

