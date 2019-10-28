#include "ClapTrap.hpp"
#include <iostream>
#include <ctime>

ClapTrap::ClapTrap()
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
    std::cout << this->_name << "Clap init!" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name):
_hit_points(100), _max_hit_points(100),
_energy_points(100), _max_energy_points(100),
_level(1), _name(name),
_melee_attack_damage(30), _ranged_attack_damage(20), _armor_damage_reduction(5)
{
    std::cout << this->_name << ": Clap init!" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << this->_name << ": Clap init!" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Clap destroy!" << std::endl;
    return;
}

ClapTrap&
ClapTrap::operator =(ClapTrap const & rhs)
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
