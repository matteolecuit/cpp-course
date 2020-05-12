math.a: math.o
	ar rcs math.a math.o

math.o: math.cpp math.hpp
	g++ -c math.cpp -o math.o
	
clean: 
	rm *.o main