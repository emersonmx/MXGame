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

#include <mxgame/physics/bullet_simulation.hpp>

namespace mxgame {

BulletSimulation::BulletSimulationListenerList BulletSimulation::listeners_;

void BulletSimulation::Setup(btDynamicsWorld* world, bool pre_tick) {
    world->setInternalTickCallback(BulletSimulation::FireTick, NULL, pre_tick);
}

void BulletSimulation::Add(BulletSimulationListener* listener) {
    if (listener != NULL) {
        listeners_.push_back(listener);
    }
}

void BulletSimulation::Remove(BulletSimulationListener* listener) {
    if (listener != NULL) {
        listeners_.remove(listener);
    }
}

void BulletSimulation::Clear() {
    listeners_.clear();
}

void BulletSimulation::FireTick(btDynamicsWorld* world, btScalar time_step) {
    BulletSimulationListenerList::iterator it;
    for (it = listeners_.begin(); it != listeners_.end(); ++it) {
        (*it)->Tick(world, time_step);
    }
}

} /* namespace mxgame */

