SOURCES=../src/mxgame/system/time/system_time.cpp \
		../src/mxgame/system/time/clock.cpp

CXX=g++
LDFLAGS=-lrt
CPPFLAGS=-I../src
DEFINES=-DHAVE_CLOCK_GETTIME -DHAVE_NANOSLEEP

all: objects test

objects: $(SOURCES)
	$(CXX) -c $^ $(DEFINES) $(CPPFLAGS)
	
test:
	$(CXX) -o ../test/time_test ../test/time_test.cpp *.o \
				 $(CPPFLAGS) $(LDFLAGS)
	
.PHONY: clean
clean:
	rm *.o