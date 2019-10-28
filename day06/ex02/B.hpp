#pragma once

#include "Base.hpp"

class B: public Base
{
private:
    B&  operator=(B const &);
    B(B const &);
public:
    B();
    ~B();
};