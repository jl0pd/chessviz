all: prog

prog: main.o commands.o checks.o bin build
	gcc -std=c11 build/main.o build/commands.o build/checks.o -o bin/chess.test
test: main_test.o commands_test.o checks_test.o bin build
	gcc -std=c11 -I thirdparty/ctest.h build/main_test.o build/commands_test.o build/checks_test.o -o bin/chess.test

main.o: src/main.c build
	gcc -std=c11 -c src/main.c -o build/main.o
commands.o: src/commands.c build
	gcc -std=c11 -c src/commands.c -o build/commands.o
checks.o: src/checks.c build
	gcc -std=c11 -c src/checks.c -o build/checks.o

main_test.o: test/main_test.c build
	gcc -std=c11 -c test/main_test.c -o build/main_test.o
commands_test.o: test/commands_test.c build
	gcc -std=c11 -c test/commands_test.c -o build/commands_test.o
checks_test.o: test/checks_test.c build
	gcc -std=c11 -c test/checks_test.c -o build/checks_test.o

clean:
	rm -rf build
bin:
	mkdir bin
build:
	mkdir build