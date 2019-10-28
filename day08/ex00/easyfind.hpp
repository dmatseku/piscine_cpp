#pragma once

#include <vector>
#include <exception>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T container, int elem)
{
    typename T::iterator iter = container.begin();
    typename T::iterator end = container.end();

    iter = std::find(iter, end, elem);
    // for (; iter != end; ++iter)
    //     if (*iter == elem)
    //         return (iter);

    if (iter == end)
        throw std::exception();
    return (iter);
}