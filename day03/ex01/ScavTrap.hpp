#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>

class ScavTrap
{
private:
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
    ScavTrap();
    ScavTrap(std::string);
    ScavTrap(ScavTrap const &);
    ~ScavTrap();

    ScavTrap&       operator=(ScavTrap const &);

    void            rangedAttack(std::string const &);
    void            meleeAttack(std::string const &);

    void            takeDamage(unsigned int);
    void            beRepaired(unsigned int);
    void            challengeNewcomer();
};
#endif