#include "FragTrap.hpp"
#include <iostream>
#include <ctime>

FragTrap::FragTrap()
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
    std::cout << this->_name << "Let's get this party started!" << std::endl;
    return;
}

FragTrap::FragTrap(std::string name):
_hit_points(100), _max_hit_points(100),
_energy_points(100), _max_energy_points(100),
_level(1), _name(name),
_melee_attack_damage(30), _ranged_attack_damage(20), _armor_damage_reduction(5)
{
    std::cout << this->_name << ": Let's get this party started!" << std::endl;
    return;
}

FragTrap::FragTrap(FragTrap const & src)
{
    std::cout << this->_name << ": Let's get this party started!" << std::endl;
    *this = src;
}

FragTrap::~FragTrap()
{
    std::cout << this->_name << ": Good bye!" << std::endl;
    return;
}

FragTrap&
FragTrap::operator =(FragTrap const & rhs)
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
FragTrap::rangedAttack(std::string const & target)
{
    std::cout << "[FR4G-TP \"" << this->_name << "\" attacks \"" << target
              << "\" at range, causing " << this->_ranged_attack_damage
              << " points of damage]" << std::endl;
    std::cout << this->_name << ": Take that!" << std::endl;
}

void
FragTrap::meleeAttack(std::string const & target)
{
    std::cout << "[FR4G-TP \"" << this->_name << "\" attacks \"" << target
              << "\" at melee, causing " << this->_melee_attack_damage
              << " points of damage]" << std::endl;
    std::cout << this->_name << ": Heyyah!" << std::endl;
}

void
FragTrap::customAttack_1(std::string const & target)
{
    std::cout << "[FR4G-TP \"" << this->_name << "\" attacks \"" << target
              << "\" at custom, causing " << this->_melee_attack_damage + 10
              << " points of damage]" << std::endl;
    std::cout << this->_name << ": WOW! I hit 'em!" << std::endl;
}

void
FragTrap::customAttack_2(std::string const & target)
{
    std::cout << "[FR4G-TP \"" << this->_name << "\" attacks \"" << target
              << "\" at custom, causing " << this->_melee_attack_damage + 20
              << " points of damage]" << std::endl;
    std::cout << this->_name << ": That looks like it hurts!" << std::endl;
}

void
FragTrap::customAttack_3(std::string const & target)
{
    std::cout << "[FR4G-TP \"" << this->_name << "\" attacks \"" << target
              << "\" at custom, causing " << this->_melee_attack_damage + 30
              << " points of damage]" << std::endl;
    std::cout << this->_name << ": Extra ouch!" << std::endl;
}

void
FragTrap::customAttack_4(std::string const & target)
{
    std::cout << "[FR4G-TP \"" << this->_name << "\" attacks \"" << target
              << "\" at custom, causing " << this->_melee_attack_damage + 40
              << " points of damage]" << std::endl;
    std::cout << this->_name << ": Crit-i-cal!" << std::endl;
}

void
FragTrap::customAttack_5(std::string const & target)
{
    std::cout << "[FR4G-TP \"" << this->_name << "\" attacks \"" << target
              << "\" at custom, causing " << this->_melee_attack_damage + 50
              << " points of damage]" << std::endl;
    std::cout << this->_name << ": Oh god I can't stop!" << std::endl;
}

void
FragTrap::takeDamage(unsigned int amount)
{
    std::cout << "[FR4G-TP \"" << this->_name << "\" was damaged, received " << amount
              << " points of damage]" << std::endl;
    if (this->_hit_points > amount - this->_armor_damage_reduction)
    {
        this->_hit_points -= (amount - this->_armor_damage_reduction);
        std::cout << this->_name << ": Why did they build me out of galvanized flesh?!" << std::endl;
    }
    else
    {
        this->_hit_points = 0;
        std::cout << this->_name << ": My robotic flesh! AAHH!" << std::endl;
    }
}

void
FragTrap::beRepaired(unsigned int amount)
{
    std::cout << "[FR4G-TP \"" << this->_name << "\" was repaired, received " << amount
              << " points of health]" << std::endl;
    if (this->_hit_points + amount < _max_hit_points)
    {
        this->_hit_points += amount;
        std::cout << this->_name << ": Health! Eww, what flavor is red?" << std::endl;
    }
    else
    {
        this->_hit_points = _max_hit_points;
        std::cout << this->_name << ": Sweet life juice!" << std::endl;
    }
}

void
FragTrap::vaulthunter_dot_exe(std::string const & target)
{
    if (this->_energy_points >= 25)
    {
        void (FragTrap::*funcs[])(std::string const & target) = 
        {
            &FragTrap::customAttack_1,
            &FragTrap::customAttack_2,
            &FragTrap::customAttack_3,
            &FragTrap::customAttack_4,
            &FragTrap::customAttack_5
        };
        (this->*funcs[rand() % 5])(target);
        this->_energy_points -= 25;
        std::cout << "[FR4G-TP \"" << this->_name << "\" energy reduced, causing " << 25
              << " points of energy]" << std::endl;
        std::cout << this->_name << ": This time it'll be awesome, I promise!" << std::endl;
        
    }
    else
    {
        this->_energy_points = 0;
        std::cout << "[FR4G-TP \"" << this->_name << "\" energy is over]" << std::endl;
    }
}
