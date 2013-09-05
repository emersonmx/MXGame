AM_CPPFLAGS = \
	-Wall \
	-I$(top_srcdir)/src

lib_LTLIBRARIES = \
	libmxgame_system_time.la

libmxgame_system_time_la_SOURCES = \
	system_timer.cpp

if WITH_BOOST_ASIO
libmxgame_system_time_la_SOURCES += \
	boost_timer.cpp
endif

libmxgame_system_time_la_LDFLAGS = \
	-version-info 0:0:0

