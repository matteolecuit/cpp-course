main: main.o SDLProgram.o 
	g++ main.o SDLProgram.o -lSDL2 -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

SDLProgram.o: SDLProgram.cpp SDLProgram.hpp
	g++ -fPIC -I/usr/include/SDL2 -c SDLProgram.cpp -o SDLProgram.o  

clean:
	rm *.o