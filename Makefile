CC=gcc
COPT=-O2 -std=c99 -g

CPP=g++
CPPOPT=-O2

all:	fftlog.o fftlog++.o  test.out

fftlog.o: src/fftlog.c include/fftlog.h 
	$(CC) $(COPT) -c -o fftlog.o -Iinclude src/fftlog.c

fftlog++.o: src/fftlog++.cpp include/fftlog.hpp include/fftlog.h 
	$(CPP) $(CPPOPT) -c -o fftlog++.o -Iinclude src/fftlog++.cpp

test.out: test/test.c fftlog.o 
	$(CC) $(COPT) -g -o test.out  -Iinclude test/test.c fftlog.o -lm -lfftw3
	./test.out

clean:
	rm *.o *.out
