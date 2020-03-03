main: main.o string.a
	g++  main.o string.a -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

string.o: string.cpp
	g++ -c string.cpp -o string.o

string.a: string.o
	ar rcs string.a string.o

string.so: string.o
	g++ -shared -o string.so string.o
	
clean:
	rm *.o main