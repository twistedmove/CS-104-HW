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


all: bsttest rbtest rb_test teams

bsttest.o: bsttest.cpp bst.h
	$(CC) -c $< -o $@ $(CPPFLAGS)

bsttest: bsttest.o
	$(CC) $^ -o $@ $(CPPFLAGS)

rbtest.o: rbtest.cpp rbbst.h
	$(CC) -c $< -o $@ $(CPPFLAGS)

rbtest: rbtest.o
	$(CC) $^ -o $@ $(CPPFLAGS)

rb_test.o: rb_test.cpp rbbst.h
	$(CC) -c $< -o $@ $(CPPFLAGS)

rb_test: rb_test.o
	$(CC) $^ -o $@ $(CPPFLAGS)

teams.o: teams.cpp
	$(CC) -c $< -o $@ $(CPPFLAGS)

teams: teams.o
	$(CC) $^ -o $@ $(CPPFLAGS)

# The clean rule
.PHONY: clean
clean:
	rm -rf *o *~ bsttest rbtest rb_test teams