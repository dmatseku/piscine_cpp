#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>

class Enemy
{
private:
    int                 _hp;
    std::string         _type;
public:
    Enemy();
    Enemy(const Enemy&);
    Enemy(int hp, std::string const &);
    virtual ~Enemy();
    
    Enemy&              operator =(const Enemy&);

    const std::string   getType() const;
    int                 getHP() const;
    virtual void        takeDamage(int);
};
#endif