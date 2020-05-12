#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Character.hpp"

class Warrior : public virtual Character
{
public:
    Warrior(int health, int damage, float weaponForce);
    void attack(Character &other);

protected:
    float weaponForce = 1.0;
    using Character::heal;
};

#endif