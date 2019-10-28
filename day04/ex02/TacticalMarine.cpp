#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine()
{
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
    *this = src;
    std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine()
{
    std::cout << "Aaargh ..." << std::endl;
}


TacticalMarine&
TacticalMarine::operator =(TacticalMarine const & src)
{
    (void)src;
    return (*this);
}


ISpaceMarine*
TacticalMarine::clone() const
{
    return (new TacticalMarine(*this));
}

void
TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT !" << std::endl;
}

void
TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with bolter *" << std::endl;
}

void
TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with chainsword *" << std::endl;
}