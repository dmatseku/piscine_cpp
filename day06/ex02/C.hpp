#pragma once

#include "Base.hpp"

class C: public Base
{
private:
    C&  operator=(C const &);
    C(C const &);
public:
    C();
    ~C();
};