#pragma once

#include "Data.hpp"

class Serialization
{
private:
    Serialization(Serialization const &);
    Serialization&  operator=(Serialization const &);
public:
    Serialization();
    ~Serialization();

    void*   serialize();
    Data*   deserialize(void*);
};