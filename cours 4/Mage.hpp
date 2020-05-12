#ifndef MAGE_HPP
#define MAGE_HPP
#include "Character.hpp"
#include <cstdlib>

class Mage : public virtual Character
{
public:
    Mage(int health, int damage, int magicDamage, float precision);
    void magicAttack(Character &other);

protected:
    void dealPrecisionDamage(Character &other, int fullPoints, int missPoints);

private:
    int magicDamage = 0;
    float precision = 1.0;
};

#endif