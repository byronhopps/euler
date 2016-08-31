all: main

main: main.o p14.o
	gcc -g p14.o main.o -o main

main.o: main.c
	gcc -g -c main.c

p14.o: p14.c
	gcc -g -c p14.c

collatz: p14.o collatzDebug.o
	gcc -g p14.o collatzDebug.o -o collatzDebug

collatzDebug.o:
	gcc -g -c collatzDebug.c
