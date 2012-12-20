/*
  Copyright 2012 Emerson Max de Medeiros Silva

  Author: Emerson Max de Medeiros Silva <emersonmx@gmail.com>

  Implementation of Timer based on the class Timer of LazyFoo.

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

#include "mxgame/system/time/time.hpp"
#include "mxgame/system/time/timer.hpp"

namespace mxgame {
namespace Time {

Timer::Timer()
        : start_ticks_(0), paused_ticks_(0),
          started_(false), paused_(false) {}

void Timer::Start() {
    started_ = true;
    paused_ = false;

    start_ticks_ = Time::GetTicks();
}

void Timer::Stop() {
    started_ = false;
    paused_ = false;
}

void Timer::Pause() {
    if (started_ && !paused_) {
        paused_ = true;

        paused_ticks_ = Time::GetTicks() - start_ticks_;
    }
}

void Timer::Resume() {
    if (paused_) {
        paused_ = false;
        start_ticks_ = Time::GetTicks() - paused_ticks_;
        paused_ticks_ = 0;
    }
}

unsigned Timer::ticks() {
    if (started_) {
        if (paused_) {
            return paused_ticks_;
        } else {
            return Time::GetTicks() - start_ticks_;
        }
    }

    return 0;
}

} /* namespace Time */
} /* namespace mxgame */

