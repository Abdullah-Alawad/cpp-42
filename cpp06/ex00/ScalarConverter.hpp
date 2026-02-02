#ifndef SCALARCONVERTOR_HPP
# define SCALARCONVERTOR_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <climits>

class ScalarConverter
{
    public:
        static void convert(const std::string &literal);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter &operator=(const ScalarConverter &cpy);
        ~ScalarConverter();
};

bool    isChar(const std::string &literal);
bool    isInteger(const std::string &litral);
bool    isFloat(const std::string &litral);
bool    isDouble(const std::string &litral);
void    convertChar(const std::string &literal);
void    convertInteger(const std::string &litral);
void    convertFloat(const std::string &litral);
void    convertDouble(const std::string &litral);

#endif