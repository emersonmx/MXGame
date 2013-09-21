AM_CPPFLAGS = \
	-Wall \
	-I$(top_srcdir)/src

AM_CXXFLAGS = \
	-Wall

if WITH_OGRE
AM_CPPFLAGS += \
	$(OGRE_CFLAGS)

if WITH_BULLET
AM_CPPFLAGS += \
	$(BULLET_CFLAGS)

lib_LTLIBRARIES = \
	libmxgame_graphic_ogre_bullet.la

libmxgame_graphic_ogre_bullet_la_SOURCES = \
	ogre_bullet_debug_drawer.cpp

libmxgame_graphic_ogre_bullet_la_LDFLAGS = \
	-version-info 0:0:0
endif
endif

