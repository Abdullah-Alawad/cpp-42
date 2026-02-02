#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

template <typename T>
class Array
{
    private:
        T *_elements;
        unsigned int _size;
    public:
        Array(): _elements(NULL), _size(0) {}

        Array(unsigned int n): _elements(new T[n]()), _size(n) {}

        Array(const Array &cpy): _elements(NULL), _size(0)
        {
            if (cpy._size > 0)
            {
                _elements = new T[cpy._size]();
                _size = cpy._size;
                for (unsigned int i = 0; i < _size; i++)
                    _elements[i] = cpy._elements[i];
            }
        }

        Array &operator=(const Array &cpy)
        {
            if (this != &cpy)
            {
                if(_elements)
                    delete[] _elements;
                _size = cpy._size;
                if (_size > 0)
                {
                    _elements = new T[_size]();
                    for (unsigned int i = 0; i < _size; i++)
                        _elements[i] = cpy._elements[i];
                }
                else
                    _elements = NULL;
            }
            return (*this);
        }

        ~Array()
        {
            if (_elements)
                delete[] _elements;
        }

        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw OutOfBoundsException();
            return (_elements[index]);
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw OutOfBoundsException();
            return (_elements[index]);  
        }

        unsigned int size() const
        {
            return (_size);
        }

        class OutOfBoundsException: public std::exception
        {
            public: 
                virtual const char *what() const throw()
                {
                    return "Index out of bounds";
                }
        };
};

#endif