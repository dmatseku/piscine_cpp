#pragma once

#include <stack>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;


    MutantStack(): std::stack<T>() {}
    MutantStack(MutantStack const &src): std::stack<T>(src) {}
    MutantStack(std::stack<T> const &src): std::stack<T>(src) {}
    ~MutantStack() {}

    MutantStack&    operator =(MutantStack const &src)
    {
        std::stack<T>::operator =(src);
        return (*this);
    }

    iterator    begin()
    {
        return (std::begin(std::stack<T>::c));
    }

    iterator    end()
    {
        return (std::end(std::stack<T>::c));
    }
};