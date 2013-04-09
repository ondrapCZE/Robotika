CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES= basicDifferencialChassis.h mobDifferencialChassis.cpp mobDifferencialChassis.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=mobDifferencialChasis

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

