#include <iostream>
#include <iomanip>

template<typename T>
void    iter(T* array, size_t length, void (*f)(T&))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template<typename T>
void    func(T& elem)
{
    elem /= 2;
}

template<typename T>
void    print(T& elem)
{
    std::cout << std::fixed << std::setprecision(2) << elem << std::endl;
}

int main()
{
    float   array[] = {1.0f, 10.0f, 20.0f, 50.0f, 0.5f};
    char     array_1[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    
    iter(array, 5, func);
    iter(array, 5, print);
    iter(array_1, 6, print);
    return (0);
}