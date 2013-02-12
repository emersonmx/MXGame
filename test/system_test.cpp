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
#include "mxgame/application/application.hpp"
#include "mxgame/system/time/clock.hpp"
#include "mxgame/system/time/system_timer.hpp"
#include "mxgame/system/time/boost_timer.hpp"

using namespace mxgame;

class BaseApplication : public Application {
    public:
        BaseApplication()
                : count_(0), max_count_(10) {}
    protected:
        virtual void Initialize() {
            printf("Initialize()\n");
        }
        virtual void Finalize() throw() {
            printf("Finalize()\n");

            delete clock_;
            delete timer_;
        }

        virtual void Update() {
            printf("Ticks: %lu\n", clock_->tick());

            if (count_ >= max_count_ - 1) {
                Exit(EXIT_SUCCESS);
            }

            count_++;

            printf("%d/%d. Update()\n", count_, max_count_);
            int delay = rand() % 50;
            printf("Delay: %d\n", delay);
            timer_->Delay(delay);
        }

        virtual void Render() {
            printf("%d/%d. Render()\n", count_, max_count_);
        }

        Timer* timer_;
        Clock* clock_;

        int count_;
        int max_count_;
};

class SystemTimerApplication : public BaseApplication {
    protected:
        virtual void Initialize() {
            timer_ = new SystemTimer();
            timer_->Reset();
            clock_ = new Clock(timer_);
            BaseApplication::Initialize();
        }
};

class BoostTimerApplication : public BaseApplication {
    protected:
        virtual void Initialize() {
            timer_ = new BoostTimer();
            timer_->Reset();
            clock_ = new Clock(timer_);
            BaseApplication::Initialize();
        }
};

int main() {
    Application* boost_timer_application = new BoostTimerApplication();
    Application* system_timer_application = new SystemTimerApplication();

    printf("Running BoostTimerApplication\n");
    boost_timer_application->Run();
    printf("Running SystemTimerApplication\n");
    system_timer_application->Run();

    delete system_timer_application;
    delete boost_timer_application;

    return 0;
}

