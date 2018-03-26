all: prog

prog: main.o commands.o
	gcc bin/main.o bin/commands.o -o chess.test
main.o: src/main.c
	gcc -c src/main.c -o bin/main.o
commands.o: src/commands.c
	gcc -c src/commands.c -o bin/commands.o
clean:
	rm -rf *.o
