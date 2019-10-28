#include "ZombieHorde.hpp"
#include <iostream>

int main()
{
    ZombieHorde     stack(10);
    ZombieHorde*    heap = new ZombieHorde(10);

    std::cout << "~~~~Heap Boys~~~~" << std::endl;
    heap->announce();
    delete heap;
    std::cout << std::endl << "~~~~Stack Boys~~~~" << std::endl;
    stack.announce();
    return (0);
}