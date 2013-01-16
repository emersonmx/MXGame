/*
  Copyright 2012, 2013 Emerson Max de Medeiros Silva

  This file is part of pong.

  pong is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  pong is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with pong.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "mxgame/system/time/clock.hpp"
#include "mxgame/system/time/timer.hpp"

namespace mxgame {

Clock::Clock(Timer* timer, unsigned short framerate)
        : timer_(timer), framerate_(framerate) {

    Reset();
}


unsigned long Clock::tick() {
    if (framerate_ == 0) {
        framerate_ = 1;
    }

    time_ = 1000.f / framerate_;

    unsigned long delta = timer_->ticks() - last_ticks_;

    if (delta < time_) {
        timer_->Delay(time_ - delta);
    } else {
        time_ = delta;
    }

    last_ticks_ = timer_->ticks();

    return time_;
}

void Clock::Reset() {
    timer_->Reset();
    time_ = 0L;
    last_ticks_ = 0L;
}

} /* namespace mxgame */

