#ifndef PEON_HPP
#define PEON_HPP
#include "Victim.hpp"

class Peon: public Victim
{
public:
    Peon();
    Peon(std::string);
    Peon(const Peon &);
    ~Peon();

    Peon            &operator =(const Peon &);

    void            getPolymorphed() const;
};
#endif