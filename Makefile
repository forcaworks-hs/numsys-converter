CC ?= gcc

all:
	$(CC) -Wall -o ./numsys-cv ./src/main.c

clean: 
	rm -rfv ./numsys-cv