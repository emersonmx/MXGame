/*
  Copyright (C) 2013 Emerson Max de Medeiros Silva

  Modified version from
    <http://www.ogre3d.org/tikiwiki/BulletDebugDrawer&structure=Cookbook>

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

#include <mxgame/ogre/bullet/debug/drawer.hpp>

#include <OgreManualObject.h>
#include <OgreRoot.h>

#include <mxgame/ogre/bullet/util/converter.hpp>

namespace mxgame {
namespace ogre {
namespace bullet {
namespace debug {

Drawer::Drawer(Ogre::SceneManager* scene_manager)
        : debug_modes_(DBG_DrawWireframe) {

    contact_points_ = &contact_points1_;
    lines_ = new Ogre::ManualObject("mxgame/ogre/bullet/debug/drawer/lines");
    lines_->setDynamic(true);
    triangles_ =
        new Ogre::ManualObject("mxgame/ogre/bullet/debug/drawer/triangles");
    triangles_->setDynamic(true);

    scene_manager->getRootSceneNode()->attachObject(lines_);
    scene_manager->getRootSceneNode()->attachObject(triangles_);

    const char* material_name = "mxgame_ogre_bullet_debug_default";
    Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton()
        .getDefaultSettings()->clone(material_name);
    material->setReceiveShadows(false);
    material->setSceneBlending(Ogre::SBT_TRANSPARENT_ALPHA);
    material->setDepthBias(0.1, 0);
    Ogre::TextureUnitState* texture_unit_state = material->getTechnique(0)->
        getPass(0)->createTextureUnitState();
    texture_unit_state->setColourOperationEx(Ogre::LBX_SOURCE1,
                                             Ogre::LBS_DIFFUSE);
    material->getTechnique(0)->setLightingEnabled(false);

    lines_->begin(material_name, Ogre::RenderOperation::OT_LINE_LIST);
        lines_->position(Ogre::Vector3::ZERO);
        lines_->colour(Ogre::ColourValue::Blue);
        lines_->position(Ogre::Vector3::ZERO);
        lines_->colour(Ogre::ColourValue::Blue);

    triangles_->begin(material_name);
        triangles_->position(Ogre::Vector3::ZERO);
        triangles_->colour(Ogre::ColourValue::Blue);
        triangles_->position(Ogre::Vector3::ZERO);
        triangles_->colour(Ogre::ColourValue::Blue);
        triangles_->position(Ogre::Vector3::ZERO);
        triangles_->colour(Ogre::ColourValue::Blue);

    Ogre::Root::getSingleton().addFrameListener(this);
}

Drawer::~Drawer() {
    Ogre::Root::getSingleton().removeFrameListener(this);

    delete lines_;
    delete triangles_;
}

void Drawer::setDebugMode (int debug_mode) {
    debug_modes_ = (DebugDrawModes) debug_mode;
}

int Drawer::getDebugMode () const {
    return debug_modes_;
}

void Drawer::drawLine (const btVector3& from, const btVector3& to,
                       const btVector3& color) {

    Ogre::ColourValue colour_value = mxgame::ogre::bullet::util::color::Convert(color);
    colour_value.saturate();

    lines_->position(mxgame::ogre::bullet::util::vector::Convert(from));
    lines_->colour(colour_value);
    lines_->position(mxgame::ogre::bullet::util::vector::Convert(to));
    lines_->colour(colour_value);
}

void Drawer::drawTriangle (const btVector3& v0, const btVector3& v1,
                           const btVector3& v2, const btVector3& color,
                           btScalar alpha) {

    Ogre::ColourValue colour_value =
        mxgame::ogre::bullet::util::color::Convert(color);
    colour_value.a = alpha;
    colour_value.saturate();

    triangles_->position(mxgame::ogre::bullet::util::vector::Convert(v0));
    triangles_->colour(colour_value);
    triangles_->position(mxgame::ogre::bullet::util::vector::Convert(v1));
    triangles_->colour(colour_value);
    triangles_->position(mxgame::ogre::bullet::util::vector::Convert(v2));
    triangles_->colour(colour_value);
}

void Drawer::drawContactPoint (const btVector3& point_on_b,
        const btVector3& normal_on_b, btScalar distance, int life_time,
        const btVector3& color) {

    contact_points_->resize(contact_points_->size() + 1);
    ContactPoint contact_point = contact_points_->back();
    contact_point.from = mxgame::ogre::bullet::util::vector::Convert(point_on_b);
    contact_point.to = contact_point.from +
        mxgame::ogre::bullet::util::vector::Convert(normal_on_b) * distance;
    contact_point.die_time =
        Ogre::Root::getSingleton().getTimer()->getMilliseconds() + life_time;
    contact_point.color = mxgame::ogre::bullet::util::color::Convert(color);
}

void Drawer::reportErrorWarning (const char* warning) {
    Ogre::LogManager::getSingleton().getDefaultLog()->logMessage(warning);
}

void Drawer::draw3dText (const btVector3& location, const char* text) {
}

bool Drawer::frameStarted(const Ogre::FrameEvent& event) {
    size_t now = Ogre::Root::getSingleton().getTimer()->getMilliseconds();
    ContactPointList* new_contact_points =
        (contact_points_ == &contact_points1_
            ? &contact_points2_
            : &contact_points1_);

    for (ContactPointList::iterator it = contact_points_->begin();
            it != contact_points_->end(); ++it) {

        ContactPoint& contact_point = *it;
        lines_->position(contact_point.from);
        lines_->colour(contact_point.color);
        lines_->position(contact_point.to);
        if (now <= contact_point.die_time) {
            new_contact_points->push_back(contact_point);
        }
    }

    contact_points_->clear();
    contact_points_ = new_contact_points;

    lines_->end();
    triangles_->end();

    return true;
}

bool Drawer::frameEnded(const Ogre::FrameEvent& event) {
    lines_->beginUpdate(0);
    triangles_->beginUpdate(0);

    return true;
}

} /* namespace debug */
} /* namespace bullet */
} /* namespace ogre */
} /* namespace mxgame */

