main: main.o string.o
	g++  main.o string.o -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

string.o: string.cpp
	g++ -c string.cpp -o string.o

string.a: string.o
	ar rcs string.a string.o

clean:
	rm *.o main