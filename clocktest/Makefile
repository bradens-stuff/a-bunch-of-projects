MACROS=-DSTOPWATCH_H -DCLOCK_H
FLAGS=-Wall -O2
TARGET=clocktest
FILES=main.c stopwatch.c clock.c

$(TARGET): $(FILES)
	gcc $^ $(FLAGS) -o $@ $(MACROS)

install: $(TARGET)
	mv $(TARGET) /usr/local/bin/

uninstall: $(TARGET)
	rm /usr/local/bin/$(TARGET)
	rm ./$(TARGET)
.PHONY: $(TARGET)
