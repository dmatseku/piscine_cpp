#ifndef SQUAD_HPP
#define SQUAD_HPP
#define UNIT_MAX 20

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad: public ISquad
{
private:
    int             _count;
    ISpaceMarine*   _marines[UNIT_MAX];
public:
    Squad();
    Squad(Squad const &);
    ~Squad();

    Squad&          operator =(Squad const &);

    int             getCount() const;
    ISpaceMarine*   getUnit(int) const;
    int             push(ISpaceMarine*);
};

#endif