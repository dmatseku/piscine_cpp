#include "Character.hpp"


Character::Character():
_name(""), _ap(40), _weapon(0)
{
    return;
}

Character::Character(Character const & src)
{
    *this = src;
}

Character::Character(std::string const & name):
_name(name), _ap(40), _weapon(0)
{
    return;
}

Character::~Character()
{
    return;
}


std::ostream
&operator<<(std::ostream & out, Character const & in)
{
    out << in.getName() << " has " << in.getAp() << " AP and ";
    if (in.getWeapon())
    {
        out << "wields a " << in.getWeapon()->getName();
    }
    else
    {
        out << "is unarmed";
    }
    out << std::endl;
    return (out);
}

Character&
Character::operator =(const Character& src)
{
    if (this != &src)
        *this = src;
    return (*this);
}


std::string const
Character::getName() const
{
    return (this->_name);
}

int
Character::getAp() const
{
    return (this->_ap);
}

AWeapon*
Character::getWeapon() const
{
    return (this->_weapon);
}


void
Character::recoverAP()
{
    this->_ap += 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

void
Character::equip(AWeapon* weapon)
{
    this->_weapon = weapon;
}

void
Character::attack(Enemy* enemy)
{
    if (this->_weapon)
    {
        int cost = this->_weapon->getAPCost();

        if (this->_ap >=cost)
        {
            std::cout << this->_name << " attacks " << enemy->getType()
            << " with a " << this->_weapon->getName() << std::endl;
            this->_weapon->attack();

            enemy->takeDamage(this->_weapon->getDamage());
            if (enemy->getHP() <= 0)
                delete enemy;

            this->_ap -= cost;
        }
    }
}