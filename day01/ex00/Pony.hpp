#ifndef PONY_HPP
#define PONY_HPP
#include <string>

class Pony
{
public:
    Pony(std::string);
    ~Pony();
    void        set_speed(int);
    void        set_jump_height(int);
    void        set_height(int);
    void        set_weight(int);
    void        set_name(std::string);
    void        set_age(int);
    
    int         get_speed();
    int         get_jump_height();
    int         get_height();
    int         get_weight();
    std::string get_name();
    int         get_age();

private:
    int         _speed;
    int         _jump_height;
    int         _height;
    int         _weight;
    std::string _name;
    int         _age;
};
#endif