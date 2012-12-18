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

#ifndef MXGAME_SYSTEM_TIME_TIME_HPP_
#define MXGAME_SYSTEM_TIME_TIME_HPP_

namespace mxgame {
namespace Time {

unsigned GetTicks();
void Delay(unsigned milliseconds);

} /* namespace Time */
} /* namespace mxgame */
#endif /* MXGAME_SYSTEM_TIME_TIME_HPP_ */

