flags = -Wall -Werror -std=c11

all: bin build bin/chess bin/test

bin/chess: build/main.o build/commands.o build/checks.o
	gcc $(flags) build/main.o build/commands.o build/checks.o -o bin/chess
bin/test: build/commands.o build/checks.o build/test.o build/first_test.o 
	gcc $(flags) build/test.o build/commands.o build/checks.o build/first_test.o -o bin/test

build/main.o: src/main.c
	gcc $(flags) -c src/main.c -o build/main.o
build/commands.o: src/commands.c src/commands.h
	gcc $(flags) -c src/commands.c -o build/commands.o
build/checks.o: src/checks.c src/checks.h
	gcc $(flags) -c src/checks.c -o build/checks.o

build/first_test.o: test/first_test.c
	gcc -Wall -c test/first_test.c -o build/first_test.o -Ithirdparty
build/test.o: test/test.c
	gcc $(flags) -c test/test.c -o build/test.o -Ithirdparty -Isrc

clean:
	rm -rf build
bin:
	mkdir -p bin
build:
	mkdir -p build
run:
	bin/chess
run_test:
	bin/test

