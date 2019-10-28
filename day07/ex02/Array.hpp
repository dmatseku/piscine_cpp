#pragma once

#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _size;

public:
    Array() : _array(NULL), _size(0) {}

    Array(unsigned int n) : _array(new T[n]), _size(n)
    {
        for (unsigned int i = 0; i < this->_size; i++)
            this->_array[i] = 0;
    }

    Array(Array const &src) : _size(src._size)
    {
        if (this->_size)
        {
            this->_array = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; i++)
                this->_array[i] = src->_array[i];
        }
        else
            this->_array = NULL;
    }

    ~Array()
    {
        if (this->_array != NULL)
            delete[] this->_array;
    }

    T       &operator[](unsigned int i) const
    {
        if (i >= this->_size || !this->_size)
            throw std::exception();
        return (this->_array[i]);
    }

    Array const &  operator=(Array const &src)
    {
        if (this == &src)
            return (*this);
        this->_size = src._size;
        if (this->_size)
        {
            delete[] this->_array;
            this->_array = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; i++)
                this->_array[i] = src._array[i];
        }
        else
            this->_array = NULL;
        return (*this);
    }

    unsigned int size() const
    {
        return (this->_size);
    }

    void print() const
    {
        unsigned int i = 0;

        if (!this->_array)
            return;
        for (i = 0; i < this->_size - 1; i++)
            std::cout << (this->_array[i]) << ' ';
        std::cout << (this->_array[i]) << std::endl;
    }
};