#ifndef AWEAPON_HPP
#define AWEAPON_HPP
#include <string>

class AWeapon
{
private:
        std::string         _name;
        int                 _cost;
        int                 _damage;
public:
        AWeapon();
        AWeapon(const AWeapon&);
        AWeapon(std::string const &, int, int);
        virtual ~AWeapon();

        AWeapon&            operator =(const AWeapon &);

        const std::string   getName() const;
        int                 getAPCost() const;
        int                 getDamage() const;
        virtual void        attack() const = 0;

};
#endif