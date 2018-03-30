all: prog

prog: main.o commands.o checks.o
	gcc -std=c11 bin/main.o bin/commands.o bin/checks.o -o chess.test
main.o: src/main.c bin
	gcc -std=c11 -c src/main.c -o bin/main.o
commands.o: src/commands.c bin
	gcc -std=c11 -c src/commands.c -o bin/commands.o
checks.o: src/checks.c bin
	gcc -std=c11 -c src/checks.c -o bin/checks.o
clean:
	rm -rf bin
bin:
	mkdir bin
