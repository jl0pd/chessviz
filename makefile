all:
	rm -R -f bin/
	mkdir bin/
	gcc -o bin/main.test -std=c11 -Wall main.c commands.c
