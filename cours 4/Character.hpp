#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>

class Character
{
public:
    Character(int health, int damage);
    virtual void attack(Character &other);
    void decreaseHealth(int points);
    void heal(int points);

protected:
    int health = 0;
    int damage = 0;
};

#endif
