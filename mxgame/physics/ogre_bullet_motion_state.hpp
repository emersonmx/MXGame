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

#ifndef MXGAME_PHYSICS_OGRE_BULLET_MOTION_STATE_HPP_
#define MXGAME_PHYSICS_OGRE_BULLET_MOTION_STATE_HPP_

#include <LinearMath/btMotionState.h>

#include <OgreSceneNode.h>

#include <mxgame/util/ogre_bullet_util.hpp>

namespace mxgame {

class OgreBulletMotionState : public btMotionState {
    public:
        OgreBulletMotionState(Ogre::SceneNode* node=NULL,
            const btTransform& initial_transform=btTransform::getIdentity())
                : node_(node), initial_transform_(initial_transform) {}

        virtual ~OgreBulletMotionState() {}

        inline Ogre::SceneNode* node() const { return node_; }

        inline void set_node(Ogre::SceneNode* node) { node_ = node; }

        inline void set_initial_transform(const btTransform& transform) {
            initial_transform_ = transform;
        }

        virtual void getWorldTransform(btTransform& world_transform) const {
            world_transform = initial_transform_;
        }

        virtual void setWorldTransform(const btTransform& world_transform) {
            if (node_ != NULL) {
                btQuaternion rotation = world_transform.getRotation();
                Ogre::Quaternion ogre_rotation = quaternion::Convert(rotation);

                btVector3 position = world_transform.getOrigin();
                Ogre::Vector3 ogre_position = vector::Convert(position);

                node_->setOrientation(ogre_rotation);
                node_->setPosition(ogre_position);
            }
        }

    private:
        Ogre::SceneNode* node_;
        btTransform initial_transform_;
};

} /* namespace mxgame */
#endif /* MXGAME_PHYSICS_OGRE_BULLET_MOTION_STATE_HPP_ */

