FLAGS=-Wall -O2
TARGET1=booltest
TARGET2=masktest
TARGET3=permtest
FILES1=bitmask.c booltest.c
FILES2=bitmask.c masktest.c
FILES3=bitmask.c permtest.c

$(TARGET1): $(FILES1)
	gcc $(FILES1) $(FLAGS) -o $(TARGET1)
	gcc $(FILES2) $(FLAGS) -o $(TARGET2)
	gcc $(FILES3) $(FLAGS) -o $(TARGET3)

install: $(TARGET1)
	mv $(TARGET1) /usr/local/bin/
	mv $(TARGET2) /usr/local/bin/
	mv $(TARGET3) /usr/local/bin/
	echo Installed 3 binaries: booltest, masktest and permtest

uninstall: $(TARGET1)
	rm /usr/local/bin/$(TARGET1)
	rm /usr/local/bin/$(TARGET2)
	rm /usr/local/bin/$(TARGET3)

clean: $(TARGET1)
	rm $(TARGET1)
	rm $(TARGET2)
	rm $(TARGET3)
