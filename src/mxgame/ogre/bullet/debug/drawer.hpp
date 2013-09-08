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

#ifndef MXGAME_OGRE_BULLET_DEBUG_DRAWER_HPP_
#define MXGAME_OGRE_BULLET_DEBUG_DRAWER_HPP_

#include <vector>

#include <OgreFrameListener.h>
#include <OgreVector3.h>
#include <OgreColourValue.h>

#include <LinearMath/btIDebugDraw.h>
#include <LinearMath/btVector3.h>

namespace Ogre {

class ManualObject;
class SceneManager;

} /* namespace Ogre */

namespace mxgame {
namespace ogre {
namespace bullet {
namespace debug {

class Drawer : public btIDebugDraw, public Ogre::FrameListener {
    public:
        typedef struct contact_point_t {
            Ogre::Vector3 from;
            Ogre::Vector3 to;
            Ogre::ColourValue color;
            size_t die_time;
        } ContactPoint;
        typedef std::vector<ContactPoint> ContactPointList;

        Drawer(Ogre::SceneManager* scene_manager);

        virtual ~Drawer();

        virtual void setDebugMode (int debug_mode);

        virtual int getDebugMode () const;

        virtual void drawLine (const btVector3& from, const btVector3& to,
                               const btVector3& color);

        virtual void drawTriangle (const btVector3& v0, const btVector3& v1,
            const btVector3& v2, const btVector3& color, btScalar alpha);

        virtual void drawContactPoint (const btVector3& point_on_b,
            const btVector3& normal_on_b, btScalar distance, int life_time,
            const btVector3& color);

        virtual void reportErrorWarning (const char* warning);

        virtual void draw3dText (const btVector3& location, const char* text);

    protected:
        virtual bool frameStarted(const Ogre::FrameEvent& event);
        virtual bool frameEnded(const Ogre::FrameEvent& event);

    private:
        DebugDrawModes debug_modes_;
        Ogre::ManualObject* lines_;
        Ogre::ManualObject* triangles_;

        ContactPointList* contact_points_;
        ContactPointList contact_points1_;
        ContactPointList contact_points2_;
};

} /* namespace debug */
} /* namespace bullet */
} /* namespace ogre */
} /* namespace mxgame */
#endif /* MXGAME_OGRE_BULLET_DEBUG_DRAWER_HPP_ */

