#ifndef HUMAN_HPP
#define HUMAN_HPP
#include "Brain.hpp"

class Human
{
private:
    const Brain _brain;
public:
    Human();
    ~Human();
    std::string identify() const;
    Brain       getBrain();
};
#endif