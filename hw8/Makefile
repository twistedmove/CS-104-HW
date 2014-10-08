UNAME_S=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC=g++-4.8
else
	ifeq ($(UNAME_S),Darwin)
		CC=g++-4.8
	else
		CC=g++
	endif
endif

CPPFLAGS =-std=c++11 -Wall -g 
_OBJS=$(patsubst %,%,$(wildcard *.cpp))
OBJS=$(patsubst %.cpp,%.o,$(_OBJS))


all: heapeval grades quicksort

heapeval.o: heapeval.cpp maxheap.cpp maxheap.h
	$(CC) -c $< -o $@ $(CPPFLAGS)

heapeval: heapeval.o
	$(CC) $^ -o $@ $(CPPFLAGS)

grades.o: grades.cpp maxheap.cpp maxheap.h
	$(CC) -c $< -o $@ $(CPPFLAGS)

grades: grades.o
	$(CC) $^ -o $@ $(CPPFLAGS)

quicksort.o: quicksort.cpp
	$(CC) -c $< -o $@ $(CPPFLAGS)

quicksort: quicksort.o
	$(CC) $^ -o $@ $(CPPFLAGS)

# The clean rule
.PHONY: clean
clean:
	rm -rf *o *~ heapeval grades quicksort
	