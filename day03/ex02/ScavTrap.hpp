#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
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