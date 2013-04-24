CC=g++
CFLAGS=-c -Wall -std=c++0x -O3 -lpthread
LDFLAGS= -lpthread
SOURCES= ../DifferencialniPodvozek/basicDifferencialChassis.h ../DifferencialniPodvozek/mobDifferencialChassis.cpp ../DifferencialniPodvozek/mobDifferencialChassis.h movement.cpp movement.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=movement

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

