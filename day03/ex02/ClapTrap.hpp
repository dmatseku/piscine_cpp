#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>

class ClapTrap
{
protected:
    unsigned int    _hit_points;
    unsigned int    _max_hit_points;
    unsigned int    _energy_points;
    unsigned int    _max_energy_points;
    unsigned int    _level;
    std::string     _name;
    unsigned int    _melee_attack_damage;
    unsigned int    _ranged_attack_damage;
    unsigned int    _armor_damage_reduction;

public:
    ClapTrap();
    ClapTrap(std::string);
    ClapTrap(ClapTrap const &);
    ~ClapTrap();
    ClapTrap&       operator=(ClapTrap const &);
};
#endif