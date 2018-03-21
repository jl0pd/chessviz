all:
	rm -R -f bin/
	mkdir bin/
	gcc -o bin/main.test -Wall main.c commands.c
