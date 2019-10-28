#include "Human.hpp"
#include <iostream>

void
Human::meleeAttack(std::string const & target)
{
    std::cout << "MeleeAttack: " << target << std::endl;
}

void
Human::rangedAttack(std::string const & target)
{
    std::cout << "RangedAttack: " << target << std::endl;
}

void
Human::intimidatingShout(std::string const & target)
{
    std::cout << "IntimidatingShout: " << target << std::endl;
}

void
Human::action(std::string const & action_name, std::string const & target)
{
    void (Human::*funcs[])(std::string const & target) = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout };
    std::string names[] = { "meleeAttack", "rangedAttack", "intimidatingShout" };
    int i;

    for (i = 0; i < 3; i++)
    {
        if (names[i] == action_name)
            break ;
    }
    if (i < 3)
        (this->*funcs[i])(target);
}