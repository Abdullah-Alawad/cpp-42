#ifndef WHATERVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T> T &max(T &x, T &y)
{
    return (x > y) ? x : y;
}

template <typename T> T &min(T &x, T &y)
{
    return (x < y) ? x : y;
}

template <typename T> void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

#endif