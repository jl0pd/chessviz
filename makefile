flags = -Wall -Werror -std=c11

all: bin build ./bin/chess

./bin/chess: ./build/main.o ./build/commands.o ./build/checks.o
	gcc $(flags) ./build/main.o ./build/commands.o ./build/checks.o -o ./bin/chess
test: main_test.o commands_test.o checks_test.o bin build
	gcc $(flags) -I thirdparty/ctest.h build/main_test.o build/commands_test.o build/checks_test.o -o bin/chess.test

./build/main.o: ./src/main.c
	gcc $(flags) -c ./src/main.c -o ./build/main.o
./build/commands.o: ./src/commands.c ./src/commands.h
	gcc $(flags) -c ./src/commands.c -o ./build/commands.o
./build/checks.o: ./src/checks.c ./src/checks.h
	gcc $(flags) -c ./src/checks.c -o ./build/checks.o

main_test.o: test/main_test.c build
	gcc $(flags) -c test/main_test.c -o build/main_test.o
commands_test.o: test/commands_test.c build
	gcc $(flags) -c test/commands_test.c -o build/commands_test.o
checks_test.o: test/checks_test.c build
	gcc $(flags) -c test/checks_test.c -o build/checks_test.o

clean:
	rm -rf build
bin:
	mkdir -p bin
build:
	mkdir -p build
run:
	./bin/chess

