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

#ifndef MXGAME_APPLICATION_APPLICATION_HPP_
#define MXGAME_APPLICATION_APPLICATION_HPP_

#include <cstdlib>

#include <mxgame/util/disallow_copy_assign.hpp>

namespace mxgame {
namespace application {

class Application {
    public:
        Application()
                : error_code_(EXIT_SUCCESS), running_(true) {}

        virtual ~Application() {}

        inline int error_code() const { return error_code_; }

        int Run() {
            try {
                Initialize();

                while (running_) {
                    Update();
                    Render();
                }
            } catch(...) {
                Exit(EXIT_FAILURE);
            }

            Finalize();

            return error_code_;
        }

        inline void Exit(int error_code=EXIT_SUCCESS) {
            error_code_ = error_code;
            running_ = false;
        }

    protected:
        virtual void Initialize() = 0;

        virtual void Update() = 0;

        virtual void Render() = 0;

        virtual void Finalize() throw() = 0;

    private:
        int error_code_;
        bool running_;

        DISALLOW_COPY_AND_ASSIGN(Application);
};

} /* namespace application */
} /* namespace mxgame */
#endif /* MXGAME_APPLICATION_APPLICATION_HPP_ */

