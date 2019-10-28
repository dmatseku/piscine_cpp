#include "Serialization.hpp"
#include <ctime>
#include <iostream>

int main()
{
    std::srand(std::time(0));
    Serialization ser;
    void* raw = ser.serialize();
    Data* data = ser.deserialize(raw);

    std::cout   << std::endl;
    std::cout   << "First string:  " << data->s1 << std::endl
                << "Number:        " << data->n << std::endl
                << "Second string: " << data->s2 << std::endl;
    delete[] (reinterpret_cast<char*>(raw));
    delete data;
    return (0);
}