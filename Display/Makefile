CC=g++
CFLAGS=-c -Wall -std=c++0x -O3
LDFLAGS= 
SOURCES= display.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=display

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
