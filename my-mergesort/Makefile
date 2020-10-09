main: main.o  mergesort.o
	g++ -o main main.o mergesort.o
main.o: main.cpp
	g++ -c main.cpp
mergesort.o: mergesort.cpp mergesort.h
	g++ -c mersort.cpp
clean:
	rm nain *.o
debug:
	g++ -g -o main main.cpp mergesort.cpp



