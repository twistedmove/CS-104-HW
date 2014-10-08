CC=g++
CFLAGS=-g -Wall.
DEPS = list.h map.h
OBJ = factorial.o listTest.o mapTest.o hw3q7.o 

%.o: %.cpp $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

all: factorial listTest mapTest hw3q7

factorial: factorial.o
     $(CC) -o $@ $^ $(CFLAGS)

listTest: listTest.o
	$(CC) -o $@ $^ $(CFLAGS)

mapTest: mapTest.o
	$(CC) -o $@ $^ $(CFLAGS)

hw3q7: hw3q7.o
	$(CC) -o $@ $^ $(CFLAGS)