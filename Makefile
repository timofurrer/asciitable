# variables
CC = gcc
CFLAGS = -Wall
BINDIR = $(DESTDIR)/usr/bin
NAME = asciitable

all:
	$(CC) $(CFLAGS) -o $(NAME) src/asciitable.c

clean:
	rm -f $(NAME)

install:
	install --mode=755 $(NAME) $(BINDIR)/

uninstall:
	rm -f $(BINDIR)/$(NAME)
