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

#include <cstdio>

#include "mxgame/exception/exception.hpp"

#include "mxgame/application/application.hpp"

namespace mxgame {
namespace application {

Application::Application()
        : error_code_(EXIT_SUCCESS), running_(true) {}

Application::~Application() {
}

void Application::Run() {
    try {
        Initialize();

        while (running_) {
            Update();
            Render();
        }
    } catch (mxgame::exception::Exception& exception) {
        Exit(EXIT_FAILURE);
    } catch (std::exception& exception) {
        Exit(EXIT_FAILURE);
    } catch (...) {
        Exit(EXIT_FAILURE);
    }

    Finalize();
}

} /* namespace application */
} /* namespace mxgame */

