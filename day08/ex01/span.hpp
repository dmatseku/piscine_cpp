#pragma once

#include <vector>
#include <iostream>

class Span
{
private:
    std::vector<int>    _data;
    unsigned int        _last_nb;
    unsigned int        _count;
    Span();
public:
    Span(unsigned int);
    Span(Span const &);
    ~Span();

    Span&               operator =(Span const &);

    void                addNumber(int nb);
    void                addNumber(std::vector<int>::iterator, std::vector<int>::iterator);

    int                 shortestSpan();
    int                 longestSpan();

    int                 operator[](unsigned int) const;

    unsigned int        size() const;







    class ArrayIsFullException: public std::exception
    {
    public:
        ArrayIsFullException();
        ArrayIsFullException(ArrayIsFullException const &);
        ~ArrayIsFullException() throw();

        ArrayIsFullException&       operator=(ArrayIsFullException const &);

        const char*                 what() const throw();
    };



    class TooFewElementsException: public std::exception
    {
    public:
        TooFewElementsException();
        TooFewElementsException(TooFewElementsException const &);
        ~TooFewElementsException() throw();

        TooFewElementsException&    operator=(TooFewElementsException const &);

        const char*                 what() const throw();
    };
};

std::ostream&           operator<<(std::ostream&, Span const &);