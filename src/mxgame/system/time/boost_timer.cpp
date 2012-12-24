/*
  Copyright 2012 Emerson Max de Medeiros Silva

  Author: Emerson Max de Medeiros Silva <emersonmx@gmail.com>

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

#include "mxgame/system/time/boost_timer.hpp"

namespace mxgame {

typedef boost::chrono::duration<unsigned, boost::milli> milliseconds;

BoostTimer::BoostTimer()
        : timer_(io_) {
    Reset();
}

unsigned long BoostTimer::ticks() {
    milliseconds ms =
        boost::chrono::round<milliseconds>(
                boost::chrono::steady_clock::now() - start_time_);

    return ms.count();
}

void BoostTimer::Reset() {
    start_time_ = boost::chrono::steady_clock::now();
}

void BoostTimer::Delay(unsigned long milliseconds) {
    timer_.expires_from_now(boost::posix_time::milliseconds(milliseconds));
    timer_.wait();
}

} /* namespace mxgame */

