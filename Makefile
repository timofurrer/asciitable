all:
	@gcc -Wall -o asciitable src/asciitable.c

clean:
	@rm -f asciitable
