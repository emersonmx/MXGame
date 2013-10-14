# Global configuration# {{{
ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
    -Wall

if WITH_OGRE
AM_CPPFLAGS += \
    $(OGRE_CFLAGS)
endif

if WITH_BULLET
AM_CPPFLAGS += \
    $(BULLET_CFLAGS)
endif

AM_CXXFLAGS = \
    -Wall

lib_LTLIBRARIES =
# }}}

# System# {{{
lib_LTLIBRARIES += \
    mxgame/system/libmxgame_system.la

mxgame_system_libmxgame_system_la_SOURCES = \
    mxgame/system/system_timer.cpp

mxgame_system_libmxgame_system_la_LDFLAGS = \
    -version-info 0:0:0

if WITH_BOOST
lib_LTLIBRARIES += \
    mxgame/system/libmxgame_system_boost_timer.la

mxgame_system_libmxgame_system_boost_timer_la_SOURCES = \
    mxgame/system/boost_timer.cpp

mxgame_system_libmxgame_system_boost_timer_la_LDFLAGS = \
    -version-info 0:0:0
endif
# }}}

# Graphics# {{{
if WITH_OGRE
if WITH_BULLET
lib_LTLIBRARIES += \
    mxgame/graphic/libmxgame_graphic_ogre_bullet.la

mxgame_graphic_libmxgame_graphic_ogre_bullet_la_SOURCES = \
    mxgame/graphic/ogre_bullet_debug_drawer.cpp

mxgame_graphic_libmxgame_graphic_ogre_bullet_la_LDFLAGS = \
    -version-info 0:0:0
endif
endif
# }}}

# Physics# {{{
if WITH_BULLET
lib_LTLIBRARIES += \
    mxgame/physics/libmxgame_physics_bullet.la

mxgame_physics_libmxgame_physics_bullet_la_SOURCES = \
    mxgame/physics/bullet_simulation.cpp

mxgame_physics_libmxgame_physics_bullet_la_LDFLAGS = \
    -version-info 0:0:0
endif
# }}}

# Install headers# {{{
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

# Install header that use Boost# {{{
if WITH_BOOST
nobase_include_HEADERS += \
    mxgame/system/boost_timer.hpp
endif
# }}}

# Install header that Ogre# {{{
if WITH_OGRE
nobase_include_HEADERS += \
    mxgame/config.h \
    mxgame/exception/ogre_initialize_resources_exception.hpp \
    mxgame/exception/ogre_setup_scene_exception.hpp \
    mxgame/exception/ogre_setup_root_exception.hpp \
    mxgame/exception/ogre_setup_render_window_exception.hpp \
    mxgame/exception/ogre_setup_resources_exception.hpp \
    mxgame/exception/ogre_setup_render_system_exception.hpp

# Install headers that use Ogre and Bullet# {{{
if WITH_BULLET
nobase_include_HEADERS += \
    mxgame/graphic/ogre_bullet_debug_drawer.hpp \
    mxgame/physics/ogre_bullet_motion_state.hpp \
    mxgame/util/ogre_bullet_util.hpp
endif
# }}}
endif
# }}}

# Install headers that use Bullet# {{{
if WITH_BULLET
nobase_include_HEADERS += \
    mxgame/physics/bullet_simulation_listener.hpp \
    mxgame/physics/bullet_simulation.hpp
endif
# }}}
# }}}

# Tests# {{{
MXGAME_TESTS = \
    test/application_test \
    test/system_test \
    test/util_test
TESTS  = $(MXGAME_TESTS)
check_PROGRAMS = $(MXGAME_TESTS)

test_application_test_SOURCES = test/application_test.cpp

test_system_test_SOURCES = test/system_test.cpp
test_system_test_LDADD = \
    -lboost_chrono \
    mxgame/system/libmxgame_system.la

if WITH_BOOST
test_system_test_LDADD += \
    mxgame/system/libmxgame_system_boost_timer.la
endif

test_util_test_SOURCES = test/util_test.cpp
# }}}

