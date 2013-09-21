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

#ifndef MXGAME_PHYSICS_OGRE_BULLET_DEFAULT_RIGID_BODY_BUILDER_HPP_
#define MXGAME_PHYSICS_OGRE_BULLET_DEFAULT_RIGID_BODY_BUILDER_HPP_

#ifdef DEBUG
#include <BulletCollision/CollisionShapes/btBoxShape.h>
#else
#include <BulletCollision/CollisionShapes/btBox2dShape.h>
#endif
#include <BulletCollision/CollisionShapes/btCollisionShape.h>
#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <LinearMath/btMotionState.h>

#include <OgreSceneNode.h>

#include <mxgame/physics/bullet_rigid_body_builder.hpp>
#include <mxgame/physics/ogre_bullet_motion_state.hpp>
#include <mxgame/util/ogre_bullet_util.hpp>

namespace mxgame {

class OgreBulletDefaultRigidBodyBuilder : public BulletRigidBodyBuilder {
    public:
        OgreBulletDefaultRigidBodyBuilder(Ogre::SceneNode* node=NULL)
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
            btVector3 size =
                vector::Convert(node_->_getWorldAABB().getHalfSize());

#ifdef DEBUG
            collision_shape_ = new btBoxShape(size);
#else
            collision_shape_ = new btBox2dShape(size);
#endif
        }

        virtual void BuildMotionState() {
            motion_state_ = new OgreBulletMotionState(node_);
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

} /* namespace mxgame */
#endif /* MXGAME_PHYSICS_OGRE_BULLET_DEFAULT_RIGID_BODY_BUILDER_HPP_ */

