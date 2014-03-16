FLAGS=-Wall -O2
FILES=typo.c

all: filetypo typo

filetypo:
	gcc $(FILES) -o ftypo -DUSEFILE $(FLAGS)

typo:
	gcc $(FILES) -o typo $(FLAGS)

.PHONY: filetypo typo
