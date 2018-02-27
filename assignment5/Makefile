CC = g++
C_FLAGS = -g

all: helper.o clean assignment5.cpp assignment5.hpp assignment5_func.cpp
	$(CC) $(C_FLAGS) -o assignment5 helper.o assignment5.cpp assignment5.hpp assignment5_func.cpp

helper.o: helper.cpp helper.hpp
	$(CC) $(C_FLAGS) -c helper.cpp helper.hpp
	$(RM) helper.hpp.gch

clean: assignment5
	$(RM) assignment5

run: assignment5
	./assignment5

debug: assignment5
	gdb assignment5
