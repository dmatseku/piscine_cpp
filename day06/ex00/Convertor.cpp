#include "Convertor.hpp"
#include <string>
#include <exception>
#include <stdio.h>
#include <errno.h>
#include <iostream>

static types  main_type(std::string str)
{
    double d;
    char* end;

    errno = 0;
    d = std::strtod(str.c_str(), &end);
    if ((!errno || d == +1.0f / 0.0f || d == -1.0f / 0.0f
    || d != d) && static_cast<int>(d) != d)
    {
        if (*end != 'f')
            return (DOUBLE);
        else
            return (FLOAT);
    }
    if (str.length() < 2 && (str.c_str()[0] < '0' || str.c_str()[0] > '9'))
        return (CHAR);
    return (INT);
}


void
Convertor::set_main_float(const char* str)
{
    this->f = atof(str);
    this->d = static_cast<double>(this->f);
    if (this->f == +1.0f / 0.0f || this->f == -1.0f / 0.0f
        || this->f != f)
    {
        this->i_state = false;
        this->c_state = false;
    }
    else
    {
        this->i = static_cast<int>(this->f);
        this->c = static_cast<char>(this->f);
    }
}

void
Convertor::set_main_double(const char* str)
{
    this->d = std::strtod(str, NULL);
    this->f = static_cast<float>(this->d);
    if (this->d == +1.0f / 0.0f || this->d == -1.0f / 0.0f
        || this->d != d)
    {
        this->i_state = false;
        this->c_state = false;
    }
    else
    {
        this->i = static_cast<int>(this->d);
        this->c = static_cast<char>(this->d);
    }
}

void
Convertor::set_main_int(const char* str)
{
        this->i = atoi(str);
        this->d = static_cast<double>(this->i);
        this->f = static_cast<float>(this->i);
        this->c = static_cast<char>(this->i);
}

void
Convertor::set_main_char(const char* str)
{
    if (!str[0])
    {
        this->i_state = false;
        this->c_state = false;
        this->f_state = false;
        this->d_state = false;
    }
    else
    {
        this->c = str[0];
        this->d = static_cast<double>(this->c);
        this->i = static_cast<int>(this->c);
        this->f = static_cast<float>(this->c);
    }
}

void
Convertor::set_types(types t, const char* str)
{
    this->i_state = true;
    this->c_state = true;
    this->f_state = true;
    this->d_state = true;
    if (t == DOUBLE)
        this->set_main_double(str);
    else if (t == FLOAT)
        this->set_main_float(str);
    else if (t == INT)
        this->set_main_int(str);
    else 
        this->set_main_char(str);
}

Convertor::Convertor(std::string input)
{
    this->set_types(main_type(input), input.data());
}

Convertor::Convertor(Convertor const & src)
{
    *this = src;
}

Convertor::~Convertor()
{
    return;
}

Convertor&
Convertor::operator =(Convertor const & src)
{
    if (this != &src)
        *this = src;
    return (*this);
}



Convertor::operator char()
{
    if (!this->c_state)
        throw ImpossibleException();
    if (this->c < 33 || this->c > 126)
        throw NonDisplayableException();
    return (this->c);
}

Convertor::operator int()
{   
    if (!this->i_state)
        throw ImpossibleException();
    return (this->i);
}

Convertor::operator float()
{
    if (!this->f_state)
        throw ImpossibleException();
    return (this->f);
}

Convertor::operator double()
{
    if (!this->d_state)
        throw ImpossibleException();
    return (this->d);
}











Convertor::NonDisplayableException::NonDisplayableException()
{
    return;
}

Convertor::NonDisplayableException::~NonDisplayableException() throw()
{
    return;
}

Convertor::NonDisplayableException::NonDisplayableException(NonDisplayableException const &src)
{
    *this = src;
    return;
}

Convertor::NonDisplayableException&
Convertor::NonDisplayableException::operator=(NonDisplayableException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
Convertor::NonDisplayableException::what() const throw()
{
    return ("Non displayable");
}











Convertor::ImpossibleException::ImpossibleException()
{
    return;
}

Convertor::ImpossibleException::~ImpossibleException() throw()
{
    return;
}

Convertor::ImpossibleException::ImpossibleException(ImpossibleException const &src)
{
    *this = src;
    return;
}

Convertor::ImpossibleException&
Convertor::ImpossibleException::operator=(ImpossibleException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
Convertor::ImpossibleException::what() const throw()
{
    return ("impossible");
}