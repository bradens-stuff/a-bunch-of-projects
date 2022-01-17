CFLAGS = -Wall -O2
EXE = 7seg 7seg-improved arrtest calc cal char_renderer chartest reverse reverse_file huge_bools sin collatz cycle ceasarcipher str2num mapface

all: $(EXE)

clean:
	rm $(EXE)

.PHONY: all clean

7seg: 7seg.c
7seg-improved: 7seg-improved.c
arrtest: arrtest.c
calc: calc.c
cal: cal.cpp
char_renderer: char_renderer.cpp
chartest: chartest.c
collatz: collatz.c
cycle: cycle.c
reverse: reverse.c
reverse_file: reverse_file.c
huge_bools: bool/b.cpp

sin: sin.c
	gcc $^ -o $@ $(CFLAGS) -lm

ceasarcipher: ceasarchiper.c
str2num: str2num.c
mapface: mapface.c
