SRC = f2sp.c test.c
FLAGS = -Wall -std=c99 -lm

run:test
	./test

test : $(SRC)
	gcc -o $@ $^ $(FLAGS)
clean:
	rm test