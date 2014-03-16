FLAGS=-Wall -O2
TARGET=evenodd
FILES=evenodd.c

$(TARGET): $(FILES)
	gcc $^ $(FLAGS) -o $@

install: $(TARGET)
	mv $(TARGET) /usr/local/bin/

uninstall: $(TARGET)
	rm /usr/local/bin/$(TARGET)
