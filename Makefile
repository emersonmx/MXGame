# Compiler/Preprocessor config
CFLAGS=-Wall -g
CXXFLAGS=$(CFLAGS)
CPPFLAGS=-Isrc

# Project sources and target
APPLICATION_TARGET=libmxgame_application.a
APPLICATION_SOURCES=$(wildcard src/mxgame/application/*.cpp)

SYSTEM_TARGET=libmxgame_system.a
SYSTEM_SOURCES=src/mxgame/system/time/clock.cpp
SYSTEM_SOURCES+=src/mxgame/system/time/system_time.cpp
#SYSTEM_SOURCES+=src/mxgame/system/time/boost_time.cpp

# Objects
APPLICATION_OBJECTS=$(patsubst %.cpp,%.o,$(APPLICATION_SOURCES))
SYS_OBJECTS=$(patsubst %.cpp,%.o,$(SYSTEM_SOURCES))


all: $(APPLICATION_TARGET) $(SYSTEM_TARGET)

$(APPLICATION_TARGET): $(APPLICATION_OBJECTS)
	ar rcs $@ $^

$(SYSTEM_TARGET): $(SYS_OBJECTS)
	ar rcs $@ $^

.PHONY: clean
clean:
	rm -f $(APPLICATION_TARGET)
	rm -f $(SYSTEM_TARGET)
	rm -f `find src -iname "*.o"`
