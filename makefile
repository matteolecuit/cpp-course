math.a: math.o
	ar rcs math.a math.o

math.o: math.cpp math.hpp
	g++ -c math.cpp -o math.o

test: test_runner.o
	g++ test_runner.o -lcppunit -o tests; ./tests

test_runner.o : test/test_runner.cpp
	g++ -c test/test_runner.cpp -o test_runner.o

clean: 
	rm *.o *.a tests