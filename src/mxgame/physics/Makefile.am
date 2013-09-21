AM_CPPFLAGS = \
	-Wall \
	-I$(top_srcdir)/src

if WITH_BULLET
AM_CPPFLAGS += \
	$(BULLET_CFLAGS)

lib_LTLIBRARIES = \
	libmxgame_physics_bullet.la

libmxgame_physics_bullet_la_SOURCES = \
	bullet_simulation.cpp

libmxgame_physics_bullet_la_LDFLAGS = \
	-version-info 0:0:0
endif

