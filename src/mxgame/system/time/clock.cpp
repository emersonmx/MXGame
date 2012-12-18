/*
  Copyright 2012 Emerson Max de Medeiros Silva

  Author: Emerson Max de Medeiros Silva <emersonmx@gmail.com>

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

namespace mxgame {
namespace Time {

unsigned Clock::Ticks() {
    if (framerate_ == 0) {
        framerate_ = 1;
    }

    time_ = 1000.f / framerate_;

    unsigned delta = GetTicks() - last_ticks_;

    if (delta < time_) {
        Delay(time_ - delta);
    } else {
        time_ = delta;
    }

    last_ticks_ = GetTicks();

    return time_;
}

} /* namespace Time */
} /* namespace mxgame */

