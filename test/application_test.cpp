/*
  Copyright 2012, 2013 Emerson Max de Medeiros Silva

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
#include <mxgame/core/exception.hpp>

using namespace mxgame;

class ApplicationTest : public application::Application {
    public:
        ApplicationTest(int max_count)
                : max_count_(max_count) {}

    protected:
        virtual void Initialize() {
            printf("Initialize()\n");
            count_ = 0;
        }

        virtual void Finalize() throw() {
            printf("Finalize()\n");
        }

        virtual void Update() {
            if (count_ > max_count_) {
                Exit(0);
            }

            count_++;

            printf("%d. Update()\n", count_);
        }

        virtual void Render() {
            printf("%d. Render()\n", count_);
        }

        int count_;
        int max_count_;
};

class ApplicationTestError : public ApplicationTest {
    public:
        ApplicationTestError(int max_count)
                : ApplicationTest(max_count) {}

    protected:
        virtual void Update() {
            ApplicationTest::Update();

            if (count_ > max_count_ / 2) {
                throw core::Exception("Exception occurred - "
                                      "Update(): count > max_count_ / 2");
            }
        }
};

int main() {
    int error_code;
    application::Application* application = new ApplicationTest(10);

    error_code = application->Run();
    printf("Error: %d\n", error_code);

    delete application;

    application = new ApplicationTestError(10);

    error_code = application->Run();
    printf("Error: %d\n", error_code);

    delete application;

    return 0;
}

