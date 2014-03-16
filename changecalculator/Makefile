#Two choices:
#OPTS=-DFUNC=calcplain
OPTS=-DFUNC=calcfancy
FLAGS=-Wall -O2
TARGET=changecalculator
FILES=main.c calcplain.c calcfancy.c

$(TARGET): $(FILES)
	gcc $^ $(FLAGS) -o $@ $(OPTS)

install: $(TARGET)
	sudo mv $(TARGET) /usr/local/bin/

uninstall:
	sudo rm /usr/local/bin/$(TARGET)

.PHONY: $(TARGET) install uninstall
