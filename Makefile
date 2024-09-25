CC ?= gcc
CCFLAGS = -Wall -o ./numsyscv

dev:
	$(CC) $(CCFLAGS) -g ./src/main.c
release:
	$(CC) $(CCFLAGS) -O3 ./src/main.c
	strip --strip-all ./numsyscv
all:
	$(CC) -Wall -o ./numsyscv ./src/main.c
clean:
	rm -rfv ./numsyscv
