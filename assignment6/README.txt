Assignment 6: Checkers
Alexander Nead-Work

To uncompress: tar xvzf a6.tar.gz

To compile & run: `make run size=#`, where # is 8, 10, or 12

To just compile: `make`

To just run: `./assignment6 #`, where # is 8, 10, or 12

To compile & check for memory leaks: `make memcheck size=#`, where # is 8, 10, or 12

To just check for memory leaks: `valgrind ./assignment6 size=#`, where # is 8, 10, or 12

If you leave off the size argument when running `make`, the Makefile defaults the size to be 8 (this is done on line 4 of the Makefile)
