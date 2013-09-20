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

#ifndef MXGAME_OGRE_DEFAULT_SCENE_NODE_BUILDER_HPP_
#define MXGAME_OGRE_DEFAULT_SCENE_NODE_BUILDER_HPP_

#include <mxgame/ogre/scene_node_builder.hpp>

#include <OgreSceneManager.h>

namespace mxgame {
namespace ogre {

class DefaultSceneNodeBuilder : public mxgame::ogre::SceneNodeBuilder {
    public:
        DefaultSceneNodeBuilder(Ogre::SceneManager* scene_manager=NULL,
                    const Ogre::String& scene_node_name="",
                    const Ogre::String& mesh="",
                    const Ogre::Vector3& position=Ogre::Vector3::ZERO)
                : scene_manager_(scene_manager),
                  scene_node_name_(scene_node_name), mesh_(mesh),
                  position_(position), entity_(NULL), scene_node_(NULL) {}

        inline Ogre::SceneManager* scene_manager() const {
            return scene_manager_;
        }

        inline void set_scene_manager(Ogre::SceneManager* scene_manager) {
            scene_manager_ = scene_manager;
        }

        inline Ogre::String scene_node_name() const {
            return scene_node_name_;
        }

        inline void set_scene_node_name(const Ogre::String& scene_node_name) {
            scene_node_name_ = scene_node_name;
        }

        inline Ogre::String mesh() const { return mesh_; }

        inline void set_mesh(const Ogre::String& mesh) { mesh_ = mesh; }

        inline Ogre::Entity* entity() const { return entity_; }

        virtual Ogre::SceneNode* scene_node() { return NULL; }

        virtual void BuildEntity() {
            entity_ =
                scene_manager_->createEntity(scene_node_name_ + "_entity",
                                             mesh_);
        }

        virtual void BuildSceneNode() {
            scene_node_ =
                scene_manager_->getRootSceneNode()->createChildSceneNode(
                    scene_node_name_);

            scene_node_->attachObject(entity_);
            scene_node_->setPosition(position_);
        }

    protected:
        Ogre::SceneManager* scene_manager_;
        Ogre::String scene_node_name_;
        Ogre::String mesh_;
        Ogre::Vector3 position_;

        Ogre::Entity* entity_;
        Ogre::SceneNode* scene_node_;
};


} /* namespace ogre */
} /* namespace mxgame */
#endif /* MXGAME_OGRE_DEFAULT_SCENE_NODE_BUILDER_HPP_ */

