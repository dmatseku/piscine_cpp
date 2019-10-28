#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
    this->_type = "standard";
    return;
}

ZombieEvent::~ZombieEvent()
{
    return;
}

 void       ZombieEvent::setZombieType(std::string type)
 {
    if (type == "")
        this->_type = "standard";
    else
        this->_type = type;
 }

 Zombie*    ZombieEvent::newZombie(std::string name)
 {
     return (new Zombie(name, this->_type));
 }

void        ZombieEvent::randomChump()
{
    std::string names[] = {"Fat", "Pretty boy", "Hungry", "office plankton"};
    Zombie res(names[std::rand() % 4], this->_type);
    res.announce();
}
