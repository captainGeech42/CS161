CC = g++
C_FLAGS = -g -Wall

all: helper.o assignment5.o assignment5_func.o
	$(CC) $(C_FLAGS) -o assignment5 helper.o assignment5.o assignment5_func.o

helper.o: helper.cpp helper.hpp
	$(CC) $(C_FLAGS) -c helper.cpp helper.hpp

assignment5.o: assignment5.cpp assignment5.hpp
	$(CC) $(C_FLAGS) -c assignment5.cpp assignment5.hpp

assignment5_func.o: assignment5_func.cpp assignment5.hpp helper.hpp
	$(CC) $(C_FLAGS) -c assignment5_func.cpp assignment5.hpp helper.hpp

clean:
	$(RM) *.o
	$(RM) *.gch

run: assignment5
	./assignment5

debug: assignment5
	gdb assignment5
