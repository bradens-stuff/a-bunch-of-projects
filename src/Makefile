random-string: random-string.o
	gcc $^ -o $@

%.o: %.c
	gcc -c $^ -Wall -O2

clean:
	rm *.o

.PHONY: clean
