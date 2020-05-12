
#include "MysticFighter.hpp"

MysticFighter::MysticFighter(int health, int damage, int magicDamage, float weaponForce, float precision)
    : Character(health, damage), Mage(health, damage, magicDamage, precision), Warrior(health, damage, weaponForce)
{
}

void MysticFighter::attack(Character &other)
{

    this->dealPrecisionDamage(other, (int)weaponForce * this->damage, this->damage / 2);
}