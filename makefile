all: prog clean

prog: main.o commands.o checks.o
	gcc bin/main.o bin/commands.o bin/checks.o -o chess.test
main.o: src/main.c
	gcc -c src/main.c -o bin/main.o
commands.o: src/commands.c
	gcc -c src/commands.c -o bin/commands.o
checks.o: src/checks.c
	gcc -c src/checks.c -o bin/checks.o
clean:
	rm -rf *.o bin/*.o
