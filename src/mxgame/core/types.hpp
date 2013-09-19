/*
  Copyright (C) 2013 Emerson Max de Medeiros Silva

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

#ifndef MXGAME_CORE_TYPES_HPP_
#define MXGAME_CORE_TYPES_HPP_

#include <map>
#include <string>

#include <mxgame/config.h>

namespace mxgame {

#ifdef DOUBLE_PRECISION
typedef double Real;
#else
typedef float Real;
#endif

typedef std::map<std::string, std::string> KeyValuePairList;
typedef KeyValuePairList::value_type KeyValuePair;

} /* namespace mxgame */
#endif /* MXGAME_CORE_TYPES_HPP_ */

