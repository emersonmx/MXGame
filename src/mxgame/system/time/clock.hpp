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

#ifndef MXGAME_SYSTEM_TIME_CLOCK_HPP_
#define MXGAME_SYSTEM_TIME_CLOCK_HPP_

#include "mxgame/system/time/time.hpp"

namespace mxgame {
namespace Time {

class Clock {
    public:
        static const unsigned DEFAULT_FRAMERATE = 30;

        Clock(unsigned framerate=DEFAULT_FRAMERATE)
                : time_(0), last_ticks_(GetTicks()), framerate_(framerate) {}

        inline unsigned time() const { return time_; }
        inline unsigned framerate() const { return framerate_; }
        inline void set_framerate(unsigned framerate) {
            framerate_ = framerate;
        }

        unsigned Ticks();

    private:
        unsigned time_;
        unsigned last_ticks_;

        unsigned framerate_;
};

} /* namespace Time */
} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_TIME_CLOCK_HPP_ */

