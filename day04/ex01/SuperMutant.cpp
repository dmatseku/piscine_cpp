#include "SuperMutant.hpp"

SuperMutant::SuperMutant(): Enemy::Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    return;
}

SuperMutant::SuperMutant(const SuperMutant& src): Enemy::Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    *this = src;
    return;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh ..." << std::endl;
    return;
}

SuperMutant&
SuperMutant::operator =(const SuperMutant& src)
{
    if (this != &src)
        Enemy::operator=(src);
    return (*this);
}

void
SuperMutant::takeDamage(int damage)
{
    Enemy::takeDamage(damage - 3);
}