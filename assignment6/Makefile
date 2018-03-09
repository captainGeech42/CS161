CC = g++
C_FLAGS = -g -Wall -Werror

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

run: all assignment6
	./assignment6

debug: all assignment6
	gdb assignment6

memcheck: all assignment6
	valgrind ./assignment6

compress: clean
	$(RM) peda*
	$(RM) test*
	$(RM) a6.tar.gz
	$(RM) assignment6
	tar cvzf a6.tar.gz *
