#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
private:
    std::string         _name;
    int                 _ap;
    AWeapon*            _weapon;
public:
    Character();
    Character(Character const &);
    Character(std::string const &);
    ~Character();

    Character&          operator =(const Character&);

    void                recoverAP();
    void                equip(AWeapon*);
    void                attack(Enemy*);

    std::string const   getName() const;
    int                 getAp() const;
    AWeapon*            getWeapon() const;
};

std::ostream            &operator<<(std::ostream &, Character const &);
#endif