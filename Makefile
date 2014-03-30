SHELL=/bin/bash
DEFS=-DDEFAULT_SECONDS=0

all: timer

timer:
	gcc src/{main,timer,flag}.c -o timer -Wall -O2 $(DEFS)

install: all
	sudo mv timer /usr/local/bin
	sudo cp timer.1 /usr/man/man1/

uninstall:
	sudo rm /usr/local/bin/timer
	sudo rm /usr/man/man1/timer.1

clean:
	rm src/timer

.PHONY: timer all install uninstall clean
