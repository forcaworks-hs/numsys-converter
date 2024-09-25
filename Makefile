CC ?= gcc

all:
	$(CC) -Wall -o ./numsyscv ./src/main.c

clean: 
	rm -rfv ./numsyscv