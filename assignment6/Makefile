CC = g++
C_FLAGS = -g -Wall -Werror

size = 8

all: clean helper.o assignment6.o assignment6_func.o
	$(CC) $(C_FLAGS) -o assignment6 helper.o assignment6.o assignment6_func.o

helper.o: helper.cpp helper.hpp
	$(CC) $(C_FLAGS) -c helper.cpp helper.hpp

assignment6.o: assignment6.cpp assignment6.hpp
	$(CC) $(C_FLAGS) -c assignment6.cpp assignment6.hpp

assignment6_func.o: assignment6_func.cpp assignment6.hpp helper.hpp
	$(CC) $(C_FLAGS) -c assignment6_func.cpp assignment6.hpp helper.hpp

clean:
	$(RM) *.o
	$(RM) *.gch
	$(RM) peda*

run: all assignment6
	./assignment6 $(size)

debug: all assignment6
	@echo ----When running with GDB, please set the board size by running the program with 'r [size]'----
	gdb assignment6 --silent

memcheck: all assignment6
	valgrind ./assignment6 $(size)

compress: clean
	$(RM) peda*
	$(RM) test*
	$(RM) a6.tar.gz
	$(RM) assignment6
	tar cvzf a6.tar.gz *
