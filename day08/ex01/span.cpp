#include "span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int n): _last_nb(0), _count(n)
{
    return;
}

Span::Span(Span const & rhs): _data(rhs._data), _last_nb(rhs._last_nb), _count(rhs._count)
{
    return;
}

Span::~Span()
{
    return;
}

Span&
Span::operator =(Span const & rhs)
{
    if (this != &rhs)
    {
        *this = rhs;
    }
    return (*this);
}

int
Span::operator[](unsigned int i) const
{
    if (i >= this->_last_nb)
        return (this->_data[_last_nb - 1]);
    return (this->_data[i]);
}

void
Span::addNumber(int nb)
{
    if (this->_last_nb < this->_count)
    {
        this->_data.push_back(nb);
        this->_last_nb++;
    }
    else
    {
        throw ArrayIsFullException();
    }
}

void
Span::addNumber(std::vector<int>::iterator iter, std::vector<int>::iterator end)
{
    if (std::distance(iter, end) > this->_count - this->_last_nb)
    {
        throw ArrayIsFullException();
    }
    else
        for (; iter != end; iter++, this->_last_nb++)
            this->_data.push_back(*iter);
}

int
Span::shortestSpan()
{
    int Span = INT_MAX;

    if (this->_last_nb < 2)
    {
        throw TooFewElementsException();
    }
    std::sort(this->_data.begin(), this->_data.end());
    for (unsigned int i = 1; i < this->_last_nb; i++)
    {
        if (Span > this->_data[i] - this->_data[i - 1])
            Span = this->_data[i] - this->_data[i - 1];
    }
    return (Span);
}

int
Span::longestSpan()
{
    if (this->_last_nb < 2)
    {
        throw TooFewElementsException();
    }
    std::sort(this->_data.begin(), this->_data.end());
    return (this->_data[this->_last_nb - 1] - this->_data[0]);
}

unsigned int
Span::size() const
{
    return (this->_last_nb);
}


std::ostream&
operator<<(std::ostream& out, Span const & src)
{
    unsigned int i;
    unsigned int count = src.size();

    if (!count)
        return (out);
    for (i = 0; i < count - 1; i++)
        out << src[i] << ' ';
    out << src[i] << std::endl;
    return (out);
}










Span::ArrayIsFullException::ArrayIsFullException()
{
    return;
}

Span::ArrayIsFullException::~ArrayIsFullException() throw()
{
    return;
}

Span::ArrayIsFullException::ArrayIsFullException(ArrayIsFullException const & src)
{
    *this = src;
    return;
}

Span::ArrayIsFullException&
Span::ArrayIsFullException::operator=(ArrayIsFullException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
Span::ArrayIsFullException::what() const throw()
{
    return ("Array is full!");
}









Span::TooFewElementsException::TooFewElementsException()
{
    return;
}

Span::TooFewElementsException::~TooFewElementsException() throw()
{
    return;
}

Span::TooFewElementsException::TooFewElementsException(TooFewElementsException const & src)
{
    *this = src;
    return;
}

Span::TooFewElementsException&
Span::TooFewElementsException::operator=(TooFewElementsException const & rhs)
{
    std::exception::operator=(rhs);
    return (*this);
}

const char*
Span::TooFewElementsException::what() const throw()
{
    return ("Too few elements for generate result!");
}