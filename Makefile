CC = g++
C_FLAGS = -g -Wall

ifndef num
$(error num is not set. Please re-run make with the argument `num=#`, where # is the assignment #)
endif

all:
	$(CC) $(C_FLAGS) -o assignment$(num) assignment$(num).cpp

clean: assignment$(num)
	$(RM) assignment$(num)

run: assignment$(num)
	./assignment$(num)

debug: assignment$(num)
	gdb assignment$(num)
