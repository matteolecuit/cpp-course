#include "Character.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "MysticFighter.hpp"

int main()
{
    srand(time(NULL));
    Warrior w1(100, 10, 1.1);
    Mage m1(100, 7, 6, 0.7);

    MysticFighter f1(100, 8, 5, 1.1, 0.75);
    f1.attack(m1);
    return 0;
}