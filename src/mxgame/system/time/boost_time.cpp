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

#include <boost/chrono.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "mxgame/system/time/time.hpp"

namespace mxgame {
namespace Time {

using namespace boost;

typedef chrono::duration<unsigned, milli> milliseconds;

static asio::io_service io;
static asio::deadline_timer timer(io);
static chrono::steady_clock::time_point start(chrono::steady_clock::now());

unsigned GetTicks() {
    milliseconds ms =
        chrono::round<milliseconds>(chrono::steady_clock::now() - start);
    return ms.count();
}

void Delay(unsigned milliseconds) {
    timer.expires_from_now(posix_time::milliseconds(milliseconds));
    timer.wait();
}

} /* namespace Time */
} /* namespace mxgame */

