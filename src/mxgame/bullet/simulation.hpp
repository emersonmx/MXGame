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

#ifndef MXGAME_BULLET_SIMULATION_HPP_
#define MXGAME_BULLET_SIMULATION_HPP_

#include <list>

#include <BulletDynamics/Dynamics/btDynamicsWorld.h>
#include <LinearMath/btScalar.h>

#include <mxgame/bullet/simulation_listener.hpp>

namespace mxgame {
namespace bullet {

class Simulation {
    public:
        static void Setup(btDynamicsWorld* world, bool pre_tick=false);

        static void Add(SimulationListener* listener);

        static void Remove(SimulationListener* listener);

    private:
        typedef std::list<SimulationListener*> SimulationListenerList;

        Simulation() {}

        static void FireTick(btDynamicsWorld* world, btScalar time_step);

        static SimulationListenerList listeners_;
};

} /* namespace bullet */
} /* namespace mxgame */
#endif /* MXGAME_BULLET_SIMULATION_HPP_ */

