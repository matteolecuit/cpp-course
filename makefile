main: main.o SDLProgram.o 
	g++ main.o SDLProgram.o -lSDL2 -o main

maindyn: main.o ./lib/libSDLProgram.so
	g++ -L./ -lSDLProgram main.o -o maindyn

main.o: main.cpp
	g++ -c main.cpp -o main.o

SDLProgram.o: SDLProgram.cpp SDLProgram.hpp
	g++ -fPIC -I/usr/include/SDL2 -c SDLProgram.cpp -o SDLProgram.o  

SDLProgram.a: SDLProgram.o
	ar rcs ./lib/SDLProgram.a SDLProgram.o 

SDLProgram.so: SDLProgram.o
	g++ -shared -o ./lib/libSDLProgram.so SDLProgram.o  

clean:
	rm *.o