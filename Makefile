TARGET = swarm1
LIBS = -lm
CC = g++
CFLAGS = -g -Wall

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

default: $(TARGET)
all: default

n: clean default

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@


%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

.PHONY:clean

clean:
	-rm -f *.o
	-rm -f $(TARGET)
