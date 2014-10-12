CC=g++
CFLAGS=-c -Wall
LDFLAGS= -lusb-1.0
SOURCES=main.cpp tim310.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=testTim310

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
