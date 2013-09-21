SUBDIRS = mxgame

nobase_include_HEADERS = \
	mxgame/exception/exception.hpp \
	mxgame/exception/system_exception.hpp \
	mxgame/exception/application_exception.hpp \
	mxgame/application/application.hpp \
	mxgame/core/types.hpp \
	mxgame/system/system_timer.hpp \
	mxgame/system/clock.hpp \
	mxgame/system/timer.hpp \
	mxgame/util/util.hpp

if WITH_BOOST_ASIO
nobase_include_HEADERS += \
	mxgame/system/boost_timer.hpp
endif

if WITH_OGRE
nobase_include_HEADERS += \
	mxgame/exception/ogre_initialize_resources_exception.hpp \
	mxgame/exception/ogre_setup_scene_exception.hpp \
	mxgame/exception/ogre_setup_root_exception.hpp \
	mxgame/exception/ogre_setup_render_window_exception.hpp \
	mxgame/exception/ogre_setup_resources_exception.hpp \
	mxgame/exception/ogre_setup_render_system_exception.hpp \
	mxgame/graphic/ogre_scene_node_builder.hpp \
	mxgame/graphic/ogre_default_scene_node_builder.hpp
if WITH_BULLET
nobase_include_HEADERS += \
	mxgame/graphic/ogre_bullet_debug_drawer.hpp \
	mxgame/physics/ogre_bullet_motion_state.hpp \
	mxgame/physics/ogre_bullet_default_rigid_body_builder.hpp \
	mxgame/util/ogre_bullet_util.hpp
endif
endif

if WITH_BULLET
nobase_include_HEADERS += \
	mxgame/physics/bullet_rigid_body_builder.hpp \
	mxgame/physics/bullet_simulation_listener.hpp \
	mxgame/physics/bullet_simulation.hpp
endif

