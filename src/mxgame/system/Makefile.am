AM_CPPFLAGS = \
	-Wall \
	-I$(top_srcdir)/src

lib_LTLIBRARIES = \
	libmxgame_system.la

libmxgame_system_la_SOURCES = \
	system_timer.cpp

libmxgame_system_la_LDFLAGS = \
	-version-info 0:0:0

if WITH_BOOST_ASIO
lib_LTLIBRARIES += \
	libmxgame_system_boost_timer.la

libmxgame_system_boost_timer_la_SOURCES = \
	boost_timer.cpp

libmxgame_system_boost_timer_la_LDFLAGS = \
	-version-info 0:0:0
endif
