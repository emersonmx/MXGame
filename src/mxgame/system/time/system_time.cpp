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

#include <cstdlib>
#include <sys/time.h>
#include <unistd.h>
#include "mxgame/system/time/time.hpp"

namespace mxgame {
namespace Time {

static struct timeval StartTime() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return now;
}

static struct timeval start_time = StartTime();

unsigned GetTicks() {
    struct timeval now;
    gettimeofday(&now, NULL);
    return (now.tv_sec - start_time.tv_sec) * 1000 +
           (now.tv_usec - start_time.tv_usec) / 1000;
}

void Delay(unsigned milliseconds) {
    usleep(milliseconds * 1000);
}

} /* namespace Time */
} /* namespace mxgame */

