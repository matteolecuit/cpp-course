#include "Mage.hpp"

Mage::Mage(int health, int damage, int magicDamage, float precision) : Character(health, damage)
{
    this->magicDamage = magicDamage;
    this->precision = precision;
}

void Mage::magicAttack(Character &other)
{
    this->dealPrecisionDamage(other, this->magicDamage, 0);
}

void Mage::dealPrecisionDamage(Character &other, int fullPoints, int missPoints)
{
    int randomValue = rand() % 101;
    std::cout << randomValue << std::endl;
    if (randomValue >= precision * 100)
    {
        std::cout << "Full Magic attack" << std::endl;
        other.decreaseHealth((int)(fullPoints));
    }
    else
    {
        std::cout << "Magic Attack" << std::endl;
        other.decreaseHealth((int)(missPoints));
    }
}