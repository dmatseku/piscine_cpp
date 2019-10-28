#include "Serialization.hpp"
#include <string>
#include <iostream>

Serialization::Serialization()
{
    return;
}

Serialization::~Serialization()
{
    return;
}

static std::string
serialize_nb()
{
    char        str_nb[5];
    int         nb = std::rand();
    char*       tmp;
    std::string res;

    tmp = reinterpret_cast<char*>(&nb);
    for (int i = 0; i < 4; i++)
        str_nb[i] = tmp[i];
    str_nb[4] = '\0';
    res = str_nb;
    std::cout << "serialize nb: " << nb << std::endl;
    return (res);
}

static std::string
serialize_str()
{
    char        str[9];
    int         r;
    std::string res;

    for (int i = 0; i < 8; i++)
    {
        r = 0;
        while ((r <= 48 || r > 57) && (r < 65 || r > 90) && (r < 97 || r > 122))
            r = std::rand() % 128;
        str[i] = r;
    }
    str[8] = '\0';
    res = str;
    std::cout << "serialize str: " << res << std::endl;
    return (res);
}

void*
Serialization::serialize()
{
    std::string str1 = serialize_str();
    std::string str2 = serialize_str();
    std::string str_nb = serialize_nb();
    char*       res = new char[20];
    int         j = 0;

    for (int i = 0; i < 8; i++, j++)
        res[j] = str1[i];
    for (int i = 0; i < 4; i++, j++)
        res[j] = str_nb[i];
    for (int i = 0; i < 8; i++, j++)
        res[j] = str2[i];

    return (reinterpret_cast<void*>(res));
}

Data*
Serialization::deserialize(void* raw)
{
    char*   str = reinterpret_cast<char*>(raw);
    char    tmp[9];
    Data*   res = new Data;
    int     i;

    for (i = 0; i < 8; i++)
        tmp[i] = str[i];
    tmp[8] = '\0';
    res->s1 = tmp;

    str += 8;
    res->n = (reinterpret_cast<int*>(str))[0];
    str += 4;
    
    for (i = 0; i < 8; i++)
        tmp[i] = str[i];
    res->s2 = tmp;
    return (res);
}