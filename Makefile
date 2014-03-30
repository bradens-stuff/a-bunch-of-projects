FLAGS=-Wall -O2
TARGET=fbprint
FILES=main.c fbprint.c

$(TARGET): $(FILES)
	gcc $^ $(FLAGS) -o $@ -DCELLSIZE=12

install: $(TARGET)
	mv $(TARGET) /usr/local/bin/

uninstall: $(TARGET)
	rm /usr/local/bin/$(TARGET)
	rm ./$(TARGET)
.PHONY: $(TARGET)
