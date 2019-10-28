#pragma once

#include "Base.hpp"

class A: public Base
{
private:
    A&  operator=(A const &);
    A(A const &);
public:
    A();
    ~A();
};
