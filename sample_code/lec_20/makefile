CC = gcc
FLAGS = -Wall
BINS = libdll.so testDynamic

all: $(BINS)

testDynamic: testDynamic.c
	$(CC) $(FLAGS) -o $@ $< -ldl

%.so: %.c
	$(CC) $(FLAGS) -shared -fPIC  -o $@ $<


runtest: all
	./testDynamic ./libdll.so

clean:
	rm $(BINS)