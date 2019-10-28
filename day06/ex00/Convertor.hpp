#pragma once

#include <string>


enum types
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE
};

class Convertor
{
private:
    char        c;
    int         i;
    float       f;
    double      d;
    bool        c_state;
    bool        i_state;
    bool        f_state;
    bool        d_state;
    types       main;

    void        set_main_float(const char* str);
    void        set_main_double(const char* str);
    void        set_main_int(const char* str);
    void        set_main_char(const char* str);
    void        set_types(types, const char*);
    Convertor();
public:
    Convertor(std::string);
    Convertor(Convertor const &);
    ~Convertor();

    Convertor&  operator =(Convertor const &);

    operator char();
    operator int();
    operator float();
    operator double();







    class NonDisplayableException: public std::exception
    {
    public:
        NonDisplayableException();
        NonDisplayableException(NonDisplayableException const &);
        ~NonDisplayableException() throw();

        NonDisplayableException&    operator=(NonDisplayableException const &);

        const char*	                what() const throw();
    };





    class ImpossibleException: public std::exception
    {
    public:
        ImpossibleException();
        ImpossibleException(ImpossibleException const &);
        ~ImpossibleException() throw();

        ImpossibleException&        operator=(ImpossibleException const &);

        const char*	                what() const throw();
    };
};