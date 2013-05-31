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

#ifndef MXGAME_SYSTEM_TIME_CLOCK_HPP_
#define MXGAME_SYSTEM_TIME_CLOCK_HPP_

#include <mxgame/util/disallow_copy_assign.hpp>
#include <mxgame/system/time/timer.hpp>

namespace mxgame {
namespace system {
namespace time {

class Timer;

class Clock {
    public:
        static const unsigned short DEFAULT_FRAMERATE = 30;

        Clock(Timer* timer, unsigned short framerate=DEFAULT_FRAMERATE)
                : timer_(timer), framerate_(framerate) {

            Reset();
        }

        inline unsigned long time() const { return time_; }

        inline unsigned short framerate() const { return framerate_; }

        inline void set_framerate(unsigned short framerate) {
            framerate_ = framerate;
        }

        unsigned long tick() {
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

        void Reset() {
            timer_->Reset();
            time_ = 0L;
            last_ticks_ = 0L;
        }

    private:
        Timer* timer_;

        unsigned long time_;
        unsigned long last_ticks_;

        unsigned short framerate_;

        DISALLOW_COPY_AND_ASSIGN(Clock);
};

} /* namespace time */
} /* namespace system */
} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_TIME_CLOCK_HPP_ */

