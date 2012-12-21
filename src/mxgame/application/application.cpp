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

#include "mxgame/application/application.hpp"

namespace mxgame {

void Application::Exit(int error_code) {
    error_code_ = error_code;
    running_ = false;
}

int Application::Run() {
    running_ = Initialize();

    while (running_) {
        Update();
        Render();
    }

    Finalize();

    return error_code_;
}

} /* namespace mxgame */

