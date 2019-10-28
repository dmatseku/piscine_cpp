#include <ctime>
#include "easyfind.hpp"
#include <iostream>

int main()
{
    std::vector<int>::iterator  iter;
    std::vector<int>            array;
    int number;

    std::srand(std::time(0));
    for (int i = 0; i < 10; i++)
    {
        int tmp;
        tmp = rand() % 1024 - 512;
        std::cout << tmp << ' ';
        array.push_back(tmp);
    }

    std::cout << std::endl;
    std::cout << "Choose number: ";
    std::cin >> number;

    try
    {
        iter = easyfind(array, number);
        std::cout << *iter << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Wrong number" << std::endl;
    }
    return (0);
}