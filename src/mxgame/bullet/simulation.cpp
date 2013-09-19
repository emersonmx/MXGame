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

#include <mxgame/bullet/simulation.hpp>

namespace mxgame {
namespace bullet {

Simulation::SimulationListenerList Simulation::listeners_;

void Simulation::Setup(btDynamicsWorld* world, bool pre_tick) {
    world->setInternalTickCallback(Simulation::FireTick, NULL, pre_tick);
}

void Simulation::Add(SimulationListener* listener) {
    if (listener != NULL) {
        listeners_.push_back(listener);
    }
}

void Simulation::Remove(SimulationListener* listener) {
    if (listener != NULL) {
        listeners_.remove(listener);
    }
}

void Simulation::FireTick(btDynamicsWorld* world, btScalar time_step) {
    SimulationListenerList::iterator it;
    for (it = listeners_.begin(); it != listeners_.end(); ++it) {
        (*it)->Tick(time_step);
    }
}

} /* namespace bullet */
} /* namespace mxgame */

