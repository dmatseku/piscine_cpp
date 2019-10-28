#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie
{
private:
    std::string _name;
    std::string _type;
public:
    Zombie(std::string, std::string);
    Zombie();
    ~Zombie();
    void        announce();
    void        set_name(std::string);
    void        set_type(std::string);
};
#endif