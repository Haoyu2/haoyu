

BIN = a.out
FLAGS = -Wall -std=c99 -lm


run: $(BIN)
	./$(BIN)

$(BIN): conversion.c con.c
	gcc -o $(BIN) conversion.c con.c $(FLAGS)
clean:
	rm  $(BIN)
