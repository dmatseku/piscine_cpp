#include "Array.hpp"
#include <iostream>

int main()
{
    Array <int>arr;
    Array <int>arr_1(20);

    arr = arr_1;
    arr.print();
    arr[5] = 2;
    arr_1 = arr;
    arr_1[1] = 10;
    arr = arr_1;
    arr.print();
    try
    {
        std::cout << arr[50] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
