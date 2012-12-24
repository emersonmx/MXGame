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

#ifndef MXGAME_SYSTEM_TIME_BOOST_TIMER_HPP_
#define MXGAME_SYSTEM_TIME_BOOST_TIMER_HPP_

#include <boost/chrono.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "mxgame/system/time/timer.hpp"

namespace mxgame {

class BoostTimer: public Timer {
    public:
        BoostTimer();

        virtual unsigned long ticks();

        virtual void Reset();
        virtual void Delay(unsigned long milliseconds);

    private:
        boost::asio::io_service io_;
        boost::asio::deadline_timer timer_;
        boost::chrono::steady_clock::time_point start_time_;
};

} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_TIME_BOOST_TIMER_HPP_ */

