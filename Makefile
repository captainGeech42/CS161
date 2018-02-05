CC = g++
C_FLAGS = -g -Wall

ifndef num
$(error num is not set. Please re-run make with the argument `num=#`, where # is the assignment #)
endif

all:
ifndef header
all:
	$(CC) $(C_FLAGS) -o assignment$(num) assignment$(num).cpp
else
all:
	$(CC) $(C_FLAGS) -o assignment$(num) assignment$(num).cpp assignment$(num)_func.cpp
endif

clean: assignment$(num)
	$(RM) assignment$(num)

run: assignment$(num)
	./assignment$(num)

debug: assignment$(num)
	gdb assignment$(num)
