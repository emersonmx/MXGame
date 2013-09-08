/*
  Copyright (C) 2013 Emerson Max de Medeiros Silva

  Modified version from
    <http://bulletphysics.org/mediawiki-1.5.8/index.php/MotionStates>

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

#ifndef MXGAME_OGRE_BULLET_MOTION_STATE_HPP_
#define MXGAME_OGRE_BULLET_MOTION_STATE_HPP_

#include <LinearMath/btMotionState.h>

#include <OgreSceneNode.h>

#include <mxgame/ogre/util/converter.hpp>

namespace mxgame {
namespace ogre {
namespace bullet {

class MotionState : public btMotionState {
    public:
        MotionState()
                : node_(NULL) {}

        MotionState(Ogre::SceneNode* node)
                : node_(node) {}

        virtual ~MotionState() {}

        inline Ogre::SceneNode* node() const { return node_; }

        inline void set_node(Ogre::SceneNode* node) { node_ = node; }

        virtual void getWorldTransform(btTransform& world_transform) const {
            btVector3 position = mxgame::ogre::util::vector::Convert(
                node_->getPosition());
            btQuaternion rotation = mxgame::ogre::util::quaternion::Convert(
                node_->getOrientation());

            world_transform = btTransform(rotation, position);
        }

        virtual void setWorldTransform(const btTransform& world_transform) {
            if (node_ != NULL) {
                btQuaternion rotation = world_transform.getRotation();
                Ogre::Quaternion ogre_rotation =
                    mxgame::ogre::util::quaternion::Convert(rotation);

                btVector3 position = world_transform.getOrigin();
                Ogre::Vector3 ogre_position =
                    mxgame::ogre::util::vector::Convert(position);

                node_->setOrientation(ogre_rotation);
                node_->setPosition(ogre_position);
            }
        }

    private:
        Ogre::SceneNode* node_;
};

} /* namespace bullet */
} /* namespace ogre */
} /* namespace mxgame */

#endif /* MXGAME_OGRE_BULLET_MOTION_STATE_HPP_ */

