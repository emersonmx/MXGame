SUBDIRS = mxgame

nobase_include_HEADERS = \
	mxgame/application/application.hpp \
	mxgame/application/application_exception.hpp \
	mxgame/core/exception.hpp \
	mxgame/system/time/clock.hpp \
	mxgame/system/time/system_timer.hpp \
	mxgame/system/time/timer.hpp \
	mxgame/system/system_exception.hpp \
	mxgame/util/util.hpp

if WITH_OGRE
nobase_include_HEADERS += \
	mxgame/ogre/core/initialize_resources_exception.hpp \
	mxgame/ogre/core/setup_render_system_exception.hpp \
	mxgame/ogre/core/setup_render_window_exception.hpp \
	mxgame/ogre/core/setup_resources_exception.hpp \
	mxgame/ogre/core/setup_root_exception.hpp \
	mxgame/ogre/core/setup_scene_exception.hpp
endif

if WITH_BOOST_ASIO
nobase_include_HEADERS += \
	mxgame/boost/system/time/timer.hpp
endif
