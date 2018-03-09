CC = g++
C_FLAGS = -g -Wall

all: clean helper.o assignment5.o assignment5_func.o
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

run: all assignment5
	./assignment5

debug: all assignment5
	gdb assignment5

memcheck: all assignment5
	valgrind ./assignment5

compress: clean
	$(RM) peda*
	$(RM) test*
	$(RM) a5.tar.gz
	$(RM) assignment5
	tar cvzf a5.tar.gz *
