SRCS = ArrayList.c ArrayList_Test.c test.c 
CC = gcc
FLAGS = -Wall
BINS =test debug




all: dev
	./test

test: $(SRCS)
	$(CC) $(FLAGS) -o $@ $^ 

dev:debug
	./debug >> logfile.txt

debug: $(SRCS)
	$(CC) $(FLAGS) -o $@ $^ -DDEBUG

clean:
	rm -f $(BINS) 