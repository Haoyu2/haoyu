OBJS = cal.o str.o 

CC = gcc
FLAGS = -Wall 

driver : driver.c mylib.a 
	$(CC) $(FLAGS) -o $@ $^


%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<


# The ar command allows you to create, modify, or extract archives. Following is its syntax:

# 					ar [OPTIONS] archive_name member_files

# Using the c command option to Create the archive.

# Using the r command option to replace existing or insert new file(s) into the archive.

# Using the d command option to delete files from archive

mylib.a : $(OBJS)
	ar cr $@ $^
clean :
	rm -f $(OBJS) *.a driver 