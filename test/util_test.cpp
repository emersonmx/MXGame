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

#include <cstdio>

#include <mxgame/application/application.hpp>
#include <mxgame/util/util.hpp>

class TestApplication : public mxgame::Application {
    public:
        TestApplication()
                : count_(0) {}

        virtual ~TestApplication() {}

    protected:
        virtual void Initialize() {
            printf("Initialize()\n");
        }

        virtual void Update() {
            printf("Update()\n");
            count_++;
            if (count_ > 10) {
                Exit(0);
            }

            Render();
        }

        virtual void Render() {
            printf("Render()\n");
            printf("Count: %d\n", count_);
        }

        virtual void Finalize() throw() {
            printf("Finalize()\n");
        }

    private:
        int count_;
};

MXGAME_UTIL_MAIN(new TestApplication())

