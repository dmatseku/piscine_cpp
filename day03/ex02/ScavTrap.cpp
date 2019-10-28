#include "ScavTrap.hpp"
#include <iostream>
#include <ctime>

ScavTrap::ScavTrap()
{
    this->_hit_points = 0;
    this->_max_hit_points = 0;
    this->_energy_points = 0;
    this->_max_energy_points = 0;
    this->_level = 0;
    this->_name = "";
    this->_melee_attack_damage = 0;
    this->_ranged_attack_damage = 0;
    this->_armor_damage_reduction = 0;
    std::cout << this->_name << "Recompiling my combat code!" << std::endl;
    return;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_hit_points = 100;
    this->_max_hit_points = 100;
    this->_energy_points = 50;
    this->_max_energy_points = 50;
    this->_level = 1;
    this->_name = name;
    this->_melee_attack_damage = 20;
    this->_ranged_attack_damage = 15;
    this->_armor_damage_reduction = 3;
    std::cout << this->_name << ": Recompiling my combat code!" << std::endl;
    return;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
    std::cout << this->_name << ": Recompiling my combat code!" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap()
{
    std::cout << this->_name << ": Bye!" << std::endl;
    return;
}

ScavTrap&
ScavTrap::operator =(ScavTrap const & rhs)
{
    if (this != &rhs)
    {
        this->_hit_points = rhs._hit_points;
        this->_max_hit_points = rhs._max_hit_points;
        this->_energy_points = rhs._energy_points;
        this->_max_energy_points = rhs._max_energy_points;
        this->_level = rhs._level;
        this->_name = rhs._name;
        this->_melee_attack_damage = rhs._melee_attack_damage;
        this->_ranged_attack_damage = rhs._ranged_attack_damage;
        this->_armor_damage_reduction = rhs._armor_damage_reduction;
    }
    return (*this);
}

void
ScavTrap::rangedAttack(std::string const & target)
{
    std::cout << "[ST-RB \"" << this->_name << "\" attacks \"" << target
              << "\" at range, causing " << this->_ranged_attack_damage
              << " points of damage]" << std::endl;
    std::cout << this->_name << ": I am a tornado of death and bullets!" << std::endl;
}

void
ScavTrap::meleeAttack(std::string const & target)
{
    std::cout << "[ST-RB \"" << this->_name << "\" attacks \"" << target
              << "\" at melee, causing " << this->_melee_attack_damage
              << " points of damage]" << std::endl;
    std::cout << this->_name << ": Hyah!" << std::endl;
}

void
ScavTrap::takeDamage(unsigned int amount)
{
    std::cout << "[ST-RB \"" << this->_name << "\" was damaged, received " << amount
              << " points of damage]" << std::endl;
    if (this->_hit_points > amount - this->_armor_damage_reduction)
    {
        this->_hit_points -= (amount - this->_armor_damage_reduction);
        std::cout << this->_name << ": Yikes! Ohhoho!" << std::endl;
    }
    else
    {
        this->_hit_points = 0;
        std::cout << this->_name << ": Why do I even feel pain?!" << std::endl;
    }
}

void
ScavTrap::beRepaired(unsigned int amount)
{
    std::cout << "[ST-RB \"" << this->_name << "\" was repaired, received " << amount
              << " points of health]" << std::endl;
    if (this->_hit_points + amount < _max_hit_points)
    {
        this->_hit_points += amount;
        std::cout << this->_name << ": I found health!" << std::endl;
    }
    else
    {
        this->_hit_points = _max_hit_points;
        std::cout << this->_name << ": Healsies!" << std::endl;
    }
}

void
ScavTrap::challengeNewcomer()
{
    if (this->_energy_points >= 25)
    {
        std::string targets[] = 
        {
            "Random challenge 1",
            "Random challenge 2",
            "Random challenge 3"
        };
        std::cout << "[ST-RB \"" << this->_name << "\" make " << targets[rand() % 3] << "]" << std::endl;
        this->_energy_points -= 25;
        std::cout << "[ST-RB \"" << this->_name << "\" energy reduced, causing " << 25
              << " points of energy]" << std::endl;
        std::cout << this->_name << ": This time it'll be awesome, I promise!" << std::endl;
        
    }
    else
    {
        this->_energy_points = 0;
        std::cout << "[ST-RB \"" << this->_name << "\" energy is over]" << std::endl;
    }
}
