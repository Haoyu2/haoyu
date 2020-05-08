

OBJS = hw7.o driver
arg = -n 32 -s 2020 

CC = gcc 
FLAGS = -Wall 

clean : all
	rm -f $(OBJS) *.a  *.csv

all : driver 
	./driver $(arg)
	python plot.py


driver : driver.c $(OBJS)
	$(CC) $(FLAGS) -o $@ $^ -lm

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<

