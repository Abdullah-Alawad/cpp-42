#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
    std::string fruit_type;
    int fruit_num;
};

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &cpy);
        Serializer &operator=(const Serializer &cpy);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};


#endif