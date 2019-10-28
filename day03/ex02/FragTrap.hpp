#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string);
    FragTrap(FragTrap const &);
    ~FragTrap();

    FragTrap&       operator=(FragTrap const &);

    void            rangedAttack(std::string const &);
    void            meleeAttack(std::string const &);

    void            customAttack_1(std::string const &);
    void            customAttack_2(std::string const &);
    void            customAttack_3(std::string const &);
    void            customAttack_4(std::string const &);
    void            customAttack_5(std::string const &);

    void            takeDamage(unsigned int);
    void            beRepaired(unsigned int);
    void            vaulthunter_dot_exe(std::string const &);
};
#endif