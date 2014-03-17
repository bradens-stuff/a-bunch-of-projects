FLAGS=-Wall -O2 
TARGET=asciitable
FILES=main.c table.c

$(TARGET): $(FILES)
	gcc $^ $(FLAGS) -o $@

install: $(TARGET)
	mv $(TARGET) /usr/local/bin/

uninstall:
	rm /usr/local/bin/$(TARGET)

clean:
	rm $(TARGET)

.PHONY: $(TARGET) install uninstall clean
