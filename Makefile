CC = g++

all:
	$(CC) -o assignment$(num) assignment$(num).c

run:
	./assignment$(num)

debug:
	gdb assignment$(num)
