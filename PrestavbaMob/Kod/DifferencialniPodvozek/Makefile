CC=g++
CFLAGS=-c -Wall -std=c++0x -O3 -lpthread
LDFLAGS= -lpthread
SOURCES= basicDifferencialChassis.h mobDifferencialChassis.cpp mobDifferencialChassis.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=mobDifferencialChassis

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

