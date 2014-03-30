FLAGS=-Wall -O2

all: yes

yes:
	gcc yes.c  -o yes $(FLAGS)

install: all
	sudo mv yes /usr/local/bin/

uninstall:
	sudo rm /usr/local/bin/yes

clean:
	rm yes

.PHONY: yes all install uninstall clean
