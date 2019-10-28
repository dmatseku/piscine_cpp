#include <iostream>

template<typename T>
void swap(T& var_1, T& var_2)
{
    T var_3 = var_1;

    var_1 = var_2;
    var_2 = var_3;
}

template<typename T>
T& min(T& var_1, T& var_2)
{
    if (var_1 < var_2)
        return (var_1);
    return (var_2);
}

template<typename T>
T& max(T& var_1, T& var_2)
{
    if (var_1 > var_2)
        return (var_1);
    return (var_2);
}

int main( void )
{
    int a = 2;
    int b = 3;

    swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << max( c, d ) << std::endl;
    return 0;
}