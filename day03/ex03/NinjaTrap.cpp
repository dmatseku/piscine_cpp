#include "NinjaTrap.hpp"
#include <iostream>
#include <ctime>

NinjaTrap::NinjaTrap()
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
    std::cout << "*ERROR*: connected!" << std::endl;
    return;
}

NinjaTrap::NinjaTrap(std::string name)
{
    this->_hit_points = 60;
    this->_max_hit_points = 60;
    this->_energy_points = 120;
    this->_max_energy_points = 120;
    this->_level = 1;
    this->_name = name;
    this->_melee_attack_damage = 60;
    this->_ranged_attack_damage = 5;
    this->_armor_damage_reduction = 0;
    std::cout << "*ERROR*: connected!" << std::endl;
    return;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
    std::cout << "*ERROR*: connected!" << std::endl;
    *this = src;
}

NinjaTrap::~NinjaTrap()
{
    std::cout << "*ERROR*: ..." << std::endl;
    return;
}

NinjaTrap&
NinjaTrap::operator =(NinjaTrap const & rhs)
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
NinjaTrap::rangedAttack(std::string const & target)
{
    std::cout << "[*ERROR* \"*ERROR*\" attacks \"" << target
              << "\" at range, causing " << this->_ranged_attack_damage
              << " points of damage]" << std::endl;
    std::cout << "*ERROR*: Take that!" << std::endl;
}

void
NinjaTrap::meleeAttack(std::string const & target)
{
    std::cout << "[*ERROR* \"*ERROR*\" attacks \"" << target
              << "\" at melee, causing " << this->_melee_attack_damage
              << " points of damage]" << std::endl;
    std::cout << "*ERROR*: Heyyah!" << std::endl;
}

void
NinjaTrap::takeDamage(unsigned int amount)
{
    std::cout << "[*ERROR* \"*ERROR*\" was damaged, received " << amount
              << " points of damage]" << std::endl;
    if (this->_hit_points > amount - this->_armor_damage_reduction)
    {
        this->_hit_points -= (amount - this->_armor_damage_reduction);
        std::cout << "*ERROR*: Why did they build me out of galvanized flesh?!" << std::endl;
    }
    else
    {
        this->_hit_points = 0;
        std::cout << "*ERROR*: My robotic flesh! AAHH!" << std::endl;
    }
}

void
NinjaTrap::beRepaired(unsigned int amount)
{
    std::cout << "[*ERROR* \"*ERROR*\" was repaired, received " << amount
              << " points of health]" << std::endl;
    if (this->_hit_points + amount < _max_hit_points)
    {
        this->_hit_points += amount;
        std::cout << "*ERROR*: ..." << std::endl;
    }
    else
    {
        this->_hit_points = _max_hit_points;
        std::cout << "*ERROR*: ..." << std::endl;
    }
}

void
NinjaTrap::ninjaShoebox(ClapTrap& trap)
{
    (void)trap;
    std::cout << "*ERROR*: I see you, ClapTrap!" << std::endl;
}

void
NinjaTrap::ninjaShoebox(FragTrap& trap)
{
    (void)trap;
    std::cout << "*ERROR*: I see you, FragTrap!" << std::endl;
}

void
NinjaTrap::ninjaShoebox(ScavTrap& trap)
{
    (void)trap;
    std::cout << "*ERROR*: I see you, ScavTrap!" << std::endl;
}

void
NinjaTrap::ninjaShoebox(NinjaTrap& trap)
{
    (void)trap;
    std::cout << "*ERROR*: I see you, NinjaTrap!" << std::endl;
}
