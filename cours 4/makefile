main: main.o Character.o Warrior.o Mage.o MysticFighter.o
	g++ main.o Character.o Warrior.o Mage.o MysticFighter.o -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

Character.o: Character.cpp Character.hpp
	g++ -c Character.cpp -o Character.o

Warrior.o: Warrior.cpp Warrior.hpp
	g++ -c Warrior.cpp -o Warrior.o

Mage.o: Mage.cpp Mage.hpp
	g++ -c Mage.cpp -o Mage.o

MysticFighter.o: MysticFighter.cpp MysticFighter.hpp
	g++ -c MysticFighter.cpp -o MysticFighter.o

clean: 
	rm *.o main