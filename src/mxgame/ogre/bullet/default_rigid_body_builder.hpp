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

#ifndef MXGAME_OGRE_BULLET_DEFAULT_RIGID_BODY_HPP_
#define MXGAME_OGRE_BULLET_DEFAULT_RIGID_BODY_HPP_

#include <mxgame/bullet/rigid_body_builder.hpp>

#include <BulletCollision/CollisionShapes/btBox2dShape.h>
#include <BulletCollision/CollisionShapes/btCollisionShape.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <LinearMath/btMotionState.h>

#include <mxgame/ogre/bullet/motion_state.hpp>
#include <mxgame/ogre/bullet/util/converter.hpp>

#include <OgreSceneNode.h>

namespace mxgame {
namespace ogre {
namespace bullet {

class DefaultRigidBodyBuilder : public mxgame::bullet::RigidBodyBuilder {
    public:
        DefaultRigidBodyBuilder(Ogre::SceneNode* node=NULL)
                : mass_(1.f), inertia_(btVector3(0, 0, 0)),
                  collision_shape_(NULL), motion_state_(NULL),
                  rigid_body_(NULL), node_(node) {}

        inline btScalar mass() const { return mass_; }

        inline void set_mass(btScalar mass) { mass_ = mass; }

        inline btVector3 inertia() const { return inertia_; }

        inline void set_inertia(btVector3 inertia) { inertia_ = inertia; }

        inline btCollisionShape* collision_shape() const {
            return collision_shape_;
        }

        inline btMotionState* motion_state() const { return motion_state_; }

        inline Ogre::SceneNode* node() const { return node_; }

        inline void set_node(Ogre::SceneNode* node) { node_ = node; }

        virtual btRigidBody* rigid_body() { return rigid_body_; }

        virtual void BuildColisionShape() {
            node_->_update(true, true);
            btVector3 size = mxgame::ogre::bullet::util::vector::Convert(
                    node_->_getWorldAABB().getSize());

            collision_shape_ = new btBox2dShape(size);
        }

        virtual void BuildMotionState() {
            motion_state_ = new mxgame::ogre::bullet::MotionState(node_);
        }

        virtual void BuildRigidBody() {
            if (mass_ > 0.f) {
                collision_shape_->calculateLocalInertia(mass_, inertia_);
            }

            btRigidBody::btRigidBodyConstructionInfo info(mass_, motion_state_,
                collision_shape_, inertia_);

            rigid_body_ = new btRigidBody(info);
        }

    protected:
        btScalar mass_;
        btVector3 inertia_;

        btCollisionShape* collision_shape_;
        btMotionState* motion_state_;
        btRigidBody* rigid_body_;

        Ogre::SceneNode* node_;
};

} /* namespace bullet */
} /* namespace ogre */
} /* namespace mxgame */
#endif /* MXGAME_OGRE_BULLET_DEFAULT_RIGID_BODY_HPP_ */

