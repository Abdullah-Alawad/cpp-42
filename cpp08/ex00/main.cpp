#include "EasyFind.hpp"

int     main(void)
{
    std::vector<int> x; //= {1, 2, 3, 4, 5};
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    std::vector<int> y; // = {10, 20, 30, 40, 50};
    y.push_back(10);
    y.push_back(20);
    y.push_back(30);
    y.push_back(40);
    y.push_back(50);


    try
    {
        std::vector<int>::iterator it1 = easyfind(x, 3);
        std::cout << "Found in vector: " << *it1 << std::endl;

        std::vector<int>::iterator it2 = easyfind(y, 30);
        std::cout << "Found in list: " << *it2 << std::endl;

        easyfind(x, 42); // should throw // here it says value not found 
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}