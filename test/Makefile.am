bin_PROGRAMS = \
	application_test \
	system_test

AM_CPPFLAGS = \
	-Wall \
	-I../src

AM_CXXFLAGS = \
	-Wall

AM_LDFLAGS = \
	-L../src

application_test_SOURCES = application_test.cpp
application_test_LDADD = -lmxgame_application

system_test_SOURCES = system_test.cpp
system_test_LDADD = \
	-lboost_chrono \
	-lmxgame_application \
	-lmxgame_system
