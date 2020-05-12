#include "Character.hpp"

Character::Character(int health, int damage)
{
    this->health = health;
    this->damage = damage;
}

void Character::attack(Character &other)
{
    std::cout << "Attack" << std::endl;
    other.decreaseHealth(this->damage);
}

void Character::decreaseHealth(int points)
{
    std::cout << "Health Decreased" << std::endl;
    if (points < this->health)
    {
        this->health -= points;
        return;
    }
}

void Character::heal(int points)
{
    this->health += points;
}