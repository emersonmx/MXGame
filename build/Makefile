SOURCES=../src/mxgame/system/time/time.cpp

CXX=g++
LDFLAGS=-lrt
CPPFLAGS=-I../src
DEFINES=-DHAVE_CLOCK_GETTIME -DHAVE_NANOSLEEP

all: objects test

objects: $(SOURCES)
	$(CXX) -c $^ $(DEFINES) $(CPPFLAGS)
	
test:
	$(CXX) -o ../test/time_test ../test/time_test.cpp time.o \
				 $(CPPFLAGS) $(LDFLAGS)
	
.PHONY: clean
clean:
	rm *.o