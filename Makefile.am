# Global configuration# {{{
ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
    -Wall \
    -I$(top_srcdir)/src

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

AM_LDFLAGS =

lib_LTLIBRARIES =
# }}}

# System# {{{
lib_LTLIBRARIES += \
    src/mxgame/system/libmxgame_system.la

src_mxgame_system_libmxgame_system_la_SOURCES = \
    src/mxgame/system/system_timer.cpp

src_mxgame_system_libmxgame_system_la_LDFLAGS = \
    -version-info 0:0:0

if WITH_BOOST
lib_LTLIBRARIES += \
    src/mxgame/system/libmxgame_system_boost_timer.la

src_mxgame_system_libmxgame_system_boost_timer_la_SOURCES = \
    src/mxgame/system/boost_timer.cpp

src_mxgame_system_libmxgame_system_boost_timer_la_LDFLAGS = \
    -version-info 0:0:0
endif
# }}}

# Graphics# {{{
if WITH_OGRE
if WITH_BULLET
lib_LTLIBRARIES += \
    src/mxgame/graphic/libmxgame_graphic_ogre_bullet.la

src_mxgame_graphic_libmxgame_graphic_ogre_bullet_la_SOURCES = \
    src/mxgame/graphic/ogre_bullet_debug_drawer.cpp

src_mxgame_graphic_libmxgame_graphic_ogre_bullet_la_LDFLAGS = \
    -version-info 0:0:0
endif
endif
# }}}

# Physics# {{{
if WITH_BULLET
AM_CPPFLAGS += \
    $(BULLET_CFLAGS)

lib_LTLIBRARIES += \
    src/mxgame/physics/libmxgame_physics_bullet.la

src_mxgame_physics_libmxgame_physics_bullet_la_SOURCES = \
    src/mxgame/physics/bullet_simulation.cpp

src_mxgame_physics_libmxgame_physics_bullet_la_LDFLAGS = \
    -version-info 0:0:0
endif
# }}}

# Install headers# {{{
nobase_include_HEADERS = \
    src/mxgame/exception/exception.hpp \
    src/mxgame/exception/system_exception.hpp \
    src/mxgame/exception/application_exception.hpp \
    src/mxgame/application/application.hpp \
    src/mxgame/core/types.hpp \
    src/mxgame/system/system_timer.hpp \
    src/mxgame/system/clock.hpp \
    src/mxgame/system/timer.hpp \
    src/mxgame/util/util.hpp

# Install header that use Boost# {{{
if WITH_BOOST
nobase_include_HEADERS += \
    src/mxgame/system/boost_timer.hpp
endif
# }}}

# Install header that Ogre# {{{
if WITH_OGRE
nobase_include_HEADERS += \
    src/mxgame/exception/ogre_initialize_resources_exception.hpp \
    src/mxgame/exception/ogre_setup_scene_exception.hpp \
    src/mxgame/exception/ogre_setup_root_exception.hpp \
    src/mxgame/exception/ogre_setup_render_window_exception.hpp \
    src/mxgame/exception/ogre_setup_resources_exception.hpp \
    src/mxgame/exception/ogre_setup_render_system_exception.hpp

# Install headers that use Ogre and Bullet# {{{
if WITH_BULLET
nobase_include_HEADERS += \
    src/mxgame/graphic/ogre_bullet_debug_drawer.hpp \
    src/mxgame/physics/ogre_bullet_motion_state.hpp \
    src/mxgame/util/ogre_bullet_util.hpp
endif
# }}}
endif
# }}}

# Install headers that use Bullet# {{{
if WITH_BULLET
nobase_include_HEADERS += \
    src/mxgame/physics/bullet_simulation_listener.hpp \
    src/mxgame/physics/bullet_simulation.hpp
endif
# }}}
# }}}

# Tests# {{{
if BUILD_TESTS
MXGAME_TESTS = \
    test/application_test \
    test/system_test \
    test/util_test
TESTS  = $(MXGAME_TESTS)
check_PROGRAMS = $(MXGAME_TESTS)

AM_LDFLAGS += \
    -L$(top_srcdir)/src/mxgame/system

test_application_test_SOURCES = test/application_test.cpp

test_system_test_SOURCES = test/system_test.cpp
test_system_test_LDADD = \
    -lboost_chrono \
    -lmxgame_system

if WITH_BOOST
test_system_test_LDADD += \
    -lmxgame_system_boost_timer
endif

test_util_test_SOURCES = test/util_test.cpp
endif
# }}}

