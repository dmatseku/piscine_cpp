#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain
{
private:
    std::string _name;
    std::string _address;
public:
    Brain();
    ~Brain();
    std::string get_name();
    void        set_name(std::string);
    std::string identify() const;
};
#endif