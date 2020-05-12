#include "Warrior.hpp"

Warrior::Warrior(int health, int damage, float weaponForce) : Character(health, damage)
{
    this->weaponForce = weaponForce;
}

void Warrior::attack(Character &other)
{
    std::cout << "Power attack" << std::endl;
    other.decreaseHealth((int)(this->damage * this->weaponForce));
}