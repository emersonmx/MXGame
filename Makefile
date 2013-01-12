# Compiler/Preprocessor config
CFLAGS=-Wall -g
CXXFLAGS=$(CFLAGS)
CPPFLAGS=-Isrc

# Project sources and target
SOURCES=src/mxgame/system/time/clock.cpp \
		src/mxgame/system/time/boost_timer.cpp \
		src/mxgame/system/time/system_timer.cpp \
		src/mxgame/application/application.cpp
OBJECTS=$(patsubst %.cpp,%.o,$(SOURCES))

all: $(OBJECTS)

.PHONY: clean
clean:
	rm -f `find src -iname "*.o"`
