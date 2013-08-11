noinst_PROGRAMS = \
	application_test \
	system_test \
	util_test

AM_CPPFLAGS = \
	-Wall \
	-I$(top_srcdir)/src

AM_CXXFLAGS = \
	-Wall

AM_LDFLAGS = \
	-L$(top_srcdir)/src/mxgame/system/time

application_test_SOURCES = application_test.cpp

system_test_SOURCES = system_test.cpp
system_test_LDADD = \
	-lboost_chrono \
	-lmxgame_system_time

util_test_SOURCES = util_test.cpp

