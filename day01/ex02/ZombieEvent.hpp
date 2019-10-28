#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP
#include "Zombie.hpp"

class ZombieEvent
{
private:
    std::string _type;
public:
    ZombieEvent();
    ~ZombieEvent();
    void        setZombieType(std::string);
    Zombie*     newZombie(std::string);
    void        randomChump();
};
#endif