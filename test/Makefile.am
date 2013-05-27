bin_PROGRAMS = \
	application_test \
	system_test \
	system_window_test

AM_CPPFLAGS = \
	-Wall \
	-I$(top_srcdir)/src

AM_CXXFLAGS = \
	-Wall

AM_LDFLAGS = \
	-L$(top_srcdir)/src/mxgame/application \
	-L$(top_srcdir)/src/mxgame/system/time \
	-L$(top_srcdir)/src/mxgame/system/window

application_test_SOURCES = application_test.cpp
application_test_LDADD = -lmxgame_application

system_test_SOURCES = system_test.cpp
system_test_LDADD = \
	-lboost_chrono \
	-lmxgame_application \
	-lmxgame_system_time

system_window_test_SOURCES = system_window_test.cpp
system_window_test_LDADD = \
	-lX11 \
	-lGL \
	-lmxgame_system_window \
	-lmxgame_application
