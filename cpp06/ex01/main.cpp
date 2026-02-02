#include "Serializer.hpp"

int main(void)
{
    Data info;
    info.fruit_type = "Oranges";
    info.fruit_num = 3;

    Data *original = &info;

    uintptr_t raw = Serializer::serialize(original);
    Data *restored = Serializer::deserialize(raw);

    std::cout << "the original ptr: " << original << std::endl;
    std::cout << "returned ptr:     " << restored << std::endl;

    if (original == restored)
        std::cout << "ptrs match" << std::endl;
    else 
        std::cout << "ptrs does not match" << std::endl; 
}