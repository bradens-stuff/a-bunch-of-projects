FLAGS=-Wall -O2
TARGET=rot13
FILES=rot13.c

$(TARGET): $(FILES)
	gcc $^ $(FLAGS) -o $@

install: $(TARGET)
	sudo mv $(TARGET) /usr/local/bin/

uninstall:
	sudo rm /usr/local/bin/$(TARGET)

.PHONY: $(TARGET) install uninstall
