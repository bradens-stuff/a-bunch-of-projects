OPTS=-D_R=0xFF -D_G=0xFF -D_B=0xFF -DDEFAULT_LENGTH=10 -DCELLSIZE=10 -DMARGIN=0 -DFPS=24 -std=gnu++11 -lpthread
FLAGS=-Wall -O2

all: snake

snake:
	g++ main.cc -o snake $(FLAGS) $(RES) $(OPTS) 
	@sudo chown root snake
	@sudo chmod 4755 snake

screenconfigure:
	@g++ screenconfigure.cc -o screenconfigure $(RES) -std=gnu++11
	@sudo ./screenconfigure
	@rm screenconfigure

install: snake
	sudo mv snake /usr/local/bin/

uninstall:
	sudo rm /usr/local/bin/snake

clean:
	sudo rm snake

.PHONY: snake screenconfigure install uninstall clean
