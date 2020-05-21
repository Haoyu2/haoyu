OBJS = minmaxStack.o 
CC = gcc
FLAGS = -Wall
BINS =test 

all: test
	./test

test: test.c $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ 

%.o: %.c
	$(CC) -c $(FLAGS) -o $@ $<



clean:
	rm $(BINS) $(OBJS)