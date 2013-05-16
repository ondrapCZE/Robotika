CC=g++
CFLAGS=-c -Wall -std=c++0x -O3 -lpthread
LDFLAGS= -lpthread -lusb-1.0
SOURCES= ../../../obecne/basic.cpp ../../../Tim310_driver/tim310.cpp  ../DifferencialniPodvozek/mobDifferencialChassis.cpp  movement.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=movement

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

