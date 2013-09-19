SUBDIRS = mxgame

nobase_include_HEADERS = \
	mxgame/application/application.hpp \
	mxgame/application/application_exception.hpp \
	mxgame/config.h \
	mxgame/core/exception.hpp \
	mxgame/core/types.hpp \
	mxgame/system/system_exception.hpp \
	mxgame/system/time/clock.hpp \
	mxgame/system/time/system_timer.hpp \
	mxgame/system/time/timer.hpp \
	mxgame/util/util.hpp

if WITH_BOOST_ASIO
nobase_include_HEADERS += \
	mxgame/boost/system/time/timer.hpp
endif

if WITH_OGRE
nobase_include_HEADERS += \
	mxgame/ogre/core/initialize_resources_exception.hpp \
	mxgame/ogre/core/setup_render_system_exception.hpp \
	mxgame/ogre/core/setup_render_window_exception.hpp \
	mxgame/ogre/core/setup_resources_exception.hpp \
	mxgame/ogre/core/setup_root_exception.hpp \
	mxgame/ogre/core/setup_scene_exception.hpp

if WITH_BULLET
nobase_include_HEADERS += \
	mxgame/ogre/bullet/debug/drawer.hpp \
	mxgame/ogre/bullet/util/converter.hpp \
	mxgame/ogre/bullet/motion_state.hpp
endif
endif

if WITH_BULLET
nobase_include_HEADERS += \
	mxgame/bullet/simulation.hpp \
	mxgame/bullet/simulation_listener.hpp
endif

