
main: main.o heapsort.o
	g++ -o main main.o heapsort.o
main.o: main.cpp
	g++ -c main.cpp
heapsort.o: heapsort.cpp Heap.h
	g++ -c heapsort.cpp Heap.h
clean:
	rm main *.o *.h.gch
debug: main.cpp heapsort.cpp Heap.cpp
	g++ -g -o main main.cpp heapsort.cpp



