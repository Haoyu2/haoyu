

argv = hello

all:hello.out
# 	echo "$(argv)"
# 	printf "%s\n" "$(argv)"
	./hello.out $(argv)  
# 	be carefule there is no double quotes for giving argument for hello.out

hello.out: hello.c
	gcc -o hello.out hello.c