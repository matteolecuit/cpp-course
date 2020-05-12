
#ifndef MYSTICFIGHTER_HPP
#define MYSTICFIGHTER_HPP
#include "Mage.hpp"
#include "Warrior.hpp"

class MysticFighter : public Mage, public Warrior
{
public:
    MysticFighter(int health, int damage, int magicDamage, float weaponForce, float precision);
    void attack(Character &other);
};

#endif