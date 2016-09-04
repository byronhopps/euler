all: main

main: main.o p14.o
	gcc -g -std=c99 -Ofast p14.o main.o -o main

main.o: main.c
	gcc -g -std=c99 -Ofast -c main.c

p14.o: p14.c
	gcc -g -std=c99 -Ofast -c p14.c

collatz: p14.o collatzDebug.o
	gcc -g -std=c99 -Ofast p14.o collatzDebug.o -o collatzDebug

collatzDebug.o: collatzDebug.c
	gcc -g -std=c99 -Ofast -c collatzDebug.c

clean:
	rm -f main collatzDebug *.o
