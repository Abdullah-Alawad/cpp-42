# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
        
ScalarConverter::ScalarConverter(const ScalarConverter &cpy) 
{
    (void)cpy;
}
        
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
    (void)cpy;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool    checkSigns(const std::string &literal)
{
    int i = 0;
    int sign = 0;
    while (literal[i])
    {
        if (literal[i] == '+' || literal[i] == '-')
            sign++;
        i++;
    }
    if (sign > 1)
        return true;
    return false;
}

bool check_arg(const std::string &literal)
{
    if (literal.empty() || checkSigns(literal))
        return true;
    for (int i = 0; literal[i]; i++)
    {
        if (!std::isprint(literal[i]))
            return (true);
        else if (literal.length() == 3 && (literal[0] == '\'' && literal[2] == '\''))
            return (false);
        if (isspace(literal[i]))
            return (true);
        if (ispunct(literal[i]))
        {
            if (literal[i] == '+' || literal[i] == '-' || literal[i] == '.' || literal[i] == 'f' || '\'')
            {
                i++;
                continue;
            }
            return (true);
        }
    }
    return (false);
}

void ScalarConverter::convert(const std::string &literal)
{
    if (check_arg(literal))
        std::cout << "invalid case\n";
    else if (isChar(literal))
        convertChar(literal);
       else if (isInteger(literal))
        convertInteger(literal);
   else if (isDouble(literal))
        convertDouble(literal);
   else if (isFloat(literal))
        convertFloat(literal);
   else
        std::cout << "wrong inputs\n";
}

bool    isChar(const std::string &literal)
{
    if (literal.length() == 3 && (literal[0] == '\'' && literal[2] == '\''))
        return std::isprint(static_cast<unsigned char>(literal[1]));
    else if (literal.length() == 1 && std::isprint(static_cast<unsigned int>(literal[0])))
    {
        if (isdigit(literal[0]))
            return false;
        return true;
    }
    else
        return false;
}

bool    isInteger(const std::string &literal)
{
    int i = 0;
    if (literal[0] == '+' || literal[0] == '-')
    {
        i++;
        if (literal.length() == 1)
            return false;
    }
    while (literal[i])
    {
        if (!isdigit(literal[i]))
            return (false);
        i++;
    }
    long val = std::strtol(literal.c_str(), NULL, 10);
    if (val < INT_MIN || val > INT_MAX)
        return (false);
    return (true);
}

bool    isFloat(const std::string &literal)
{
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return (true);
    if (literal[literal.length() - 1] != 'f' || literal.empty())
        return (false);
    bool dot = false;
    bool digit = false;

    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    for (; i < literal.length() - 1; i++)
    {
        if (isdigit(literal[i]))
            digit = true;
        else if (literal[i] == '.')
        {
            if (dot)
                return (false);
            dot = true;
        }
        else
            return (false);
    }
    return (dot && digit);
}

bool    isDouble(const std::string &literal)
{
    if ((literal == "nan") || (literal == "+inf") || (literal == "-inf") || literal == "inf")
        return (true);
    if (literal.empty())
        return (false);
    
    bool    dot = false;
    bool    digit = false;

    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    if (i >= literal.size())
        return (false);
    for (; i < literal.size(); i++)
    {
        if (isdigit(literal[i]))
            digit = (true);
        else if (literal[i] == '.')
        {
            if (dot)
                return (false);
            dot = (true);
        }
        else
            return (false);
    }
    return (dot && digit);
}

void    convertChar(const std::string &literal)
{
    char c;
    if (literal.length() == 3)
        c = literal[1];
    else
        c = literal[0];

    if (isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char: Non Displayable";
    
    int n = static_cast<int>(c);
    std::cout << "int: " << n << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    float f = static_cast<float>(c);
    std::cout << "float: " << f << "f" << std::endl;
    double d = static_cast<int>(c);
    std::cout << "double: " << d << std::endl;

}

void    convertInteger(const std::string &literal)
{
    int n = atoi(literal.c_str());
    char c = static_cast<char>(n);
    float f = static_cast<float>(n);
    float d = static_cast<double>(n);

    if (n < 0 || n > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(n))
        std::cout << "char: Non Displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    std::cout << "int: " << n << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" <<  std::endl;
    std::cout << "double: " << d <<  std::endl;
}

void    convertFloat(const std::string &literal)
{
    float f = strtof(literal.c_str(), NULL);
    char  c = static_cast<char>(f);
    int n = static_cast<int>(f);
    double d = static_cast<double>(f);

    if (f < 0 || f > 127 || std::isnan(f) || std::isinf(f))
        std::cout << "char: Impossible" << std::endl;
    else if (!isprint(c))
        std::cout << "char: Non Displayable" << std::endl;
    else
        std::cout << "char: " << c << std::endl;
    
    if (std::isnan(f) || std::isinf(f))
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << n << std::endl;
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f\n";
    std::cout << "double: " << d << "\n";
}

void    convertDouble(const std::string &literal)
{
    double d = strtod(literal.c_str(), NULL);
    char c = static_cast<char>(d);
    int n = static_cast<int>(d);
    float f = static_cast<float>(d);

    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << std::endl;
    
    if (std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else 
        std::cout << "int: " << n << std::endl;
    
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
