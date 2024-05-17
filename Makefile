all: compiling linking clear 

compiling:
	clang -Wall -c *.c

linking:
	clang *.o -o main

run:
	./main

clear:
	rm *.o