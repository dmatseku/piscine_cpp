#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap: public ClapTrap
{
public:
    NinjaTrap();
    NinjaTrap(std::string);
    NinjaTrap(NinjaTrap const &);
    ~NinjaTrap();

    NinjaTrap&       operator=(NinjaTrap const &);

    void            rangedAttack(std::string const &);
    void            meleeAttack(std::string const &);

    void            takeDamage(unsigned int);
    void            beRepaired(unsigned int);
    void            vaulthunter_dot_exe(std::string const &);
    void            ninjaShoebox(ClapTrap&);
    void            ninjaShoebox(FragTrap&);
    void            ninjaShoebox(ScavTrap&);
    void            ninjaShoebox(NinjaTrap&);
};
#endif