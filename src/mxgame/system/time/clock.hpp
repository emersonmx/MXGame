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

namespace mxgame {
namespace system {
namespace time {

class Timer;

class Clock {
    public:
        static const unsigned short DEFAULT_FRAMERATE = 30;

        Clock(Timer* timer, unsigned short framerate=DEFAULT_FRAMERATE);

        inline unsigned long time() const { return time_; }

        inline unsigned short framerate() const { return framerate_; }

        inline void set_framerate(unsigned short framerate) {
            framerate_ = framerate;
        }

        unsigned long tick();

        void Reset();

    private:
        Timer* timer_;

        unsigned long time_;
        unsigned long last_ticks_;

        unsigned short framerate_;
};

} /* namespace time */
} /* namespace system */
} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_TIME_CLOCK_HPP_ */

