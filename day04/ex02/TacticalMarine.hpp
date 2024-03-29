#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP
#include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
public:
    TacticalMarine();
    TacticalMarine(TacticalMarine const &);
    ~TacticalMarine();

    TacticalMarine&     operator =(TacticalMarine const &);

    ISpaceMarine*       clone() const;
    void                battleCry() const;
    void                rangedAttack() const;
    void                meleeAttack() const;
};


#endif