main: main.o Student.o
	g++ -o main main.o Student.o
main.o: main.cpp
	g++ -c main.cpp
Student.o: Student.cpp Student.h
	g++ -c Student.cpp
clean:
	rm main *.o
debug: main.cpp Student.cpp Student.
	g++ -g -o main main.cpp Student.cpp


