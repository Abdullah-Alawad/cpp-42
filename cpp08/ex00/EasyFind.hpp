#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>


class NotFound : public std::exception
{
    public:
    const char *what() const throw()
    {
        return "Value not found in container";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator looping = std::find(container.begin(), container.end(), value);
    if (looping == container.end())
        throw NotFound();
    return looping;
}

#endif 