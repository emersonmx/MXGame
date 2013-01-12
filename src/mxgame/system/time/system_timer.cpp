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

#include <cstdlib>
#include <unistd.h>
#include <sys/time.h>

#include "mxgame/system/time/system_timer.hpp"

namespace mxgame {

SystemTimer::SystemTimer() {
    Reset();
}

unsigned long SystemTimer::ticks() {
    struct timeval now;

    gettimeofday(&now, NULL);

    return (now.tv_sec - start_time_.tv_sec) * 1000 +
           (now.tv_usec - start_time_.tv_usec) / 1000;
}

void SystemTimer::Reset() {
    gettimeofday(&start_time_, NULL);
}

void SystemTimer::Delay(unsigned long milliseconds) {
    usleep(milliseconds * 1000);
}

} /* namespace mxgame */

