#Makefile
all:	compare-sort

compare-sort:	sorts.o makeArr.o main.o
	g++ -o compare-sort sorts.o makeArr.o main.o

main.o:	sorts.h main.cpp

sorts.o:	sorts.h sorts.cpp

makeArr.o:	makeArr.h makeArr.cpp

clean:
	rm -f compare-sort
	rm -f *.o