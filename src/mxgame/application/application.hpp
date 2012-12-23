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

#ifndef MXGAME_APPLICATION_APPLICATION_HPP_
#define MXGAME_APPLICATION_APPLICATION_HPP_

namespace mxgame {

class Application {
    public:
        Application() : error_code_(0), running_(true) {}
        virtual ~Application() {}

        void Exit(int error_code);
        int Run();

    protected:
        virtual bool Initialize() = 0;
        virtual void Finalize() = 0;

        virtual void Update() = 0;
        virtual void Render() = 0;

    private:
        int error_code_;
        bool running_;
};

} /* namespace mxgame */
#endif /* MXGAME_APPLICATION_APPLICATION_HPP_ */

