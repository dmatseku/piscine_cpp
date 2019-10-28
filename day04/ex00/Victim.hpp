#ifndef VICTIM_HPP
#define VICTIM_HPP
#include <string>

class Victim
{
protected:
    std::string     _name;
    void            message(std::string);
public:
    Victim();
    Victim(std::string);
    Victim(const Victim &);
    ~Victim();

    Victim          &operator =(const Victim &);

    void            introduce_message();
    virtual void    getPolymorphed() const;

    std::string     getName() const;
};

std::ostream&       operator <<(std::ostream&, const Victim&);
#endif