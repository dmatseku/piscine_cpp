#ifndef SORCERER_HPP
#define SORCERER_HPP
#include <string>
#include "Victim.hpp"

class Sorcerer
{
private:
    std::string _name;
    std::string _title;
    void        born_message();
    void        death_message();
public:
    Sorcerer();
    Sorcerer(std::string, std::string);
    Sorcerer(const Sorcerer &);
    ~Sorcerer();

    Sorcerer    &operator =(const Sorcerer &);
    
    void        introduce_message();
    void        polymorph(Victim const &) const;
    
    std::string getName() const;
    std::string getTitle() const;
};

std::ostream&   operator <<(std::ostream&, const Sorcerer&);
#endif