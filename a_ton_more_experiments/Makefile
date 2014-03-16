FLAGS=-Wall -O2
TARGS=7seg arrtest calc cal char_renderer chartest reverse reverse_file huge_bools sin collatz cycle ceasarcipher str2num mapface

all: $(TARGS)

clean:
	rm $(TARGS)

.PHONY: $(TARGS) all clean

7seg:
	gcc 7seg.c -o 7seg $(FLAGS)
arrtest:
	gcc arrtest.c -o arrtest $(FLAGS)
calc:
	gcc calc.c -o calc $(FLAGS)
cal:
	gcc cal.cpp -o cal $(FLAGS)
char_renderer:
	gcc char_renderer.cpp -o char_renderer $(FLAGS)
chartest:
	gcc chartest.c -o chartest $(FLAGS)
collatz:
	gcc collatz.c -o collatz $(FLAGS)
cycle:
	gcc cycle.c -o cycle $(FLAGS)
reverse:
	gcc reverse.c -o reverse $(FLAGS)
reverse_file:
	gcc reverse_file.c -o reverse_file $(FLAGS)
huge_bools:
	g++ bool/b.cpp -o huge_bools
sin:
	gcc sin.c -o sin $(FLAGS) -lm
ceasarcipher:
	gcc ceasarcipher.c -o ceasarcipher $(FLAGS)
str2num:
	gcc str2num.c -o str2num $(FLAGS)
mapface:
	gcc mapface.c -o mapface $(FLAGS)
