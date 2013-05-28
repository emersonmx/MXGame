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

#ifndef MXGAME_APPLICATION_APPLICATION_EXCEPTION_HPP_
#define MXGAME_APPLICATION_APPLICATION_EXCEPTION_HPP_

#include <mxgame/core/exception.hpp>

namespace mxgame {
namespace application {

class ApplicationException : public mxgame::core::Exception {
    public:
        explicit ApplicationException(const std::string& message)
            : mxgame::core::Exception("ApplicationException\n\t" + message) {}
};

} /* namespace application */
} /* namespace mxgame */
#endif /* MXGAME_APPLICATION_APPLICATION_EXCEPTION_HPP_ */

