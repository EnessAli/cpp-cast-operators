#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
    *this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
   (void)src;
   return *this;
}

ScalarConverter::~ScalarConverter(void)
{
}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal.empty())
    {
        std::cout << "Error: Empty literal" << std::endl;
        return;
    }

    LiteralType type = detectType(literal);
    
    switch (type)
    {
        case CHAR_TYPE:
            if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
                convertFromChar(literal[1]);
            else if (literal.length() == 1)
                convertFromChar(literal[0]);
            break;
        case INT_TYPE:
            convertFromInt(std::atoi(literal.c_str()));
            break;
        case FLOAT_TYPE:
            convertFromFloat(std::atof(literal.c_str()));
            break;
        case DOUBLE_TYPE:
            convertFromDouble(std::atof(literal.c_str()));
            break;
        case INVALID_TYPE:
            if (isPseudoLiteral(literal))
                handlePseudoLiteral(literal);
            else
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
            }
            break;
    }
}

LiteralType ScalarConverter::detectType(const std::string& literal)
{
    if (isChar(literal))
        return CHAR_TYPE;
    else if (isInt(literal))
        return INT_TYPE;
    else if (isFloat(literal))
        return FLOAT_TYPE;
    else if (isDouble(literal))
        return DOUBLE_TYPE;
    else
        return INVALID_TYPE;
}

bool ScalarConverter::isChar(const std::string& literal)
{
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return true;

    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        return true;
    
    return false;
}

bool ScalarConverter::isInt(const std::string& literal)
{
    if (literal.empty())
        return false;
        
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;
    
    if (start >= literal.length())
        return false;
        
    for (size_t i = start; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }

    long long value = std::atoll(literal.c_str());
    return (value >= INT_MIN && value <= INT_MAX);
}

bool ScalarConverter::isFloat(const std::string& literal)
{
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;
    
    std::string number = literal.substr(0, literal.length() - 1);
    return isValidNumber(number);
}

bool ScalarConverter::isDouble(const std::string& literal)
{
    return isValidNumber(literal);
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
    return (literal == "nanf" || literal == "+inff" || literal == "-inff" ||
            literal == "nan" || literal == "+inf" || literal == "-inf");
}

bool ScalarConverter::isValidNumber(const std::string& literal)
{
    if (literal.empty())
        return false;
    
    size_t start = 0;
    if (literal[0] == '+' || literal[0] == '-')
        start = 1;
    
    if (start >= literal.length())
        return false;
    
    bool hasDot = false;
    for (size_t i = start; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    
    return true;
}

void ScalarConverter::convertFromChar(char c)
{
    displayChar(c);
    displayInt(static_cast<int>(c));
    displayFloat(static_cast<float>(c));
    displayDouble(static_cast<double>(c));
}

void ScalarConverter::convertFromInt(int value)
{
    if (value >= 0 && value <= 127)
    {
        if (isDisplayable(static_cast<char>(value)))
            displayChar(static_cast<char>(value));
        else
            displayChar(0, false, true);
    }
    else
        displayChar(0, true);
    
    displayInt(value);
    displayFloat(static_cast<float>(value));
    displayDouble(static_cast<double>(value));
}

void ScalarConverter::convertFromFloat(float value)
{
    if (std::isnan(value) || std::isinf(value))
    {
        displayChar(0, true);
        displayInt(0, true);
        displayFloat(value);
        displayDouble(static_cast<double>(value));
        return;
    }

    if (value >= 0 && value <= 127 && value == static_cast<int>(value))
    {
        if (isDisplayable(static_cast<char>(value)))
            displayChar(static_cast<char>(value));
        else
            displayChar(0, false, true);
    }
    else
        displayChar(0, true);

    if (value >= INT_MIN && value <= INT_MAX && value == static_cast<int>(value))
        displayInt(static_cast<int>(value));
    else
        displayInt(0, true);
    
    displayFloat(value);
    displayDouble(static_cast<double>(value));
}

void ScalarConverter::convertFromDouble(double value)
{
    if (std::isnan(value) || std::isinf(value))
    {
        displayChar(0, true);
        displayInt(0, true);
        displayFloat(static_cast<float>(value));
        displayDouble(value);
        return;
    }

    if (value >= 0 && value <= 127 && value == static_cast<int>(value))
    {
        if (isDisplayable(static_cast<char>(value)))
            displayChar(static_cast<char>(value));
        else
            displayChar(0, false, true);
    }
    else
        displayChar(0, true);
    
    if (value >= INT_MIN && value <= INT_MAX && value == static_cast<int>(value))
        displayInt(static_cast<int>(value));
    else
        displayInt(0, true);
    
    displayFloat(static_cast<float>(value));
    displayDouble(value);
}

void ScalarConverter::handlePseudoLiteral(const std::string& literal)
{
    displayChar(0, true);
    displayInt(0, true);
    
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        if (literal == "nanf")
            displayFloat(std::numeric_limits<float>::quiet_NaN());
        else if (literal == "+inff")
            displayFloat(std::numeric_limits<float>::infinity());
        else if (literal == "-inff")
            displayFloat(-std::numeric_limits<float>::infinity());
        
        displayDouble(static_cast<double>(
            literal == "nanf" ? std::numeric_limits<float>::quiet_NaN() :
            literal == "+inff" ? std::numeric_limits<float>::infinity() :
            -std::numeric_limits<float>::infinity()));
    }
    else if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        if (literal == "nan")
        {
            displayFloat(std::numeric_limits<float>::quiet_NaN());
            displayDouble(std::numeric_limits<double>::quiet_NaN());
        }
        else if (literal == "+inf")
        {
            displayFloat(std::numeric_limits<float>::infinity());
            displayDouble(std::numeric_limits<double>::infinity());
        }
        else if (literal == "-inf")
        {
            displayFloat(-std::numeric_limits<float>::infinity());
            displayDouble(-std::numeric_limits<double>::infinity());
        }
    }
}

void ScalarConverter::displayChar(char c, bool impossible, bool nonDisplayable)
{
    std::cout << "char: ";
    if (impossible)
        std::cout << "impossible";
    else if (nonDisplayable)
        std::cout << "Non displayable";
    else
        std::cout << "'" << c << "'";
    std::cout << std::endl;
}

void ScalarConverter::displayInt(int value, bool impossible)
{
    std::cout << "int: ";
    if (impossible)
        std::cout << "impossible";
    else
        std::cout << value;
    std::cout << std::endl;
}

void ScalarConverter::displayFloat(float value, bool impossible)
{
    std::cout << "float: ";
    if (impossible)
        std::cout << "impossible";
    else
    {
        if (std::isnan(value))
            std::cout << "nanf";
        else if (std::isinf(value))
        {
            if (value > 0)
                std::cout << "+inff";
            else
                std::cout << "-inff";
        }
        else
        {
            std::cout << std::fixed << std::setprecision(1) << value << "f";
        }
    }
    std::cout << std::endl;
}

void ScalarConverter::displayDouble(double value, bool impossible)
{
    std::cout << "double: ";
    if (impossible)
        std::cout << "impossible";
    else
    {
        if (std::isnan(value))
            std::cout << "nan";
        else if (std::isinf(value))
        {
            if (value > 0)
                std::cout << "+inf";
            else
                std::cout << "-inf";
        }
        else
        {
            std::cout << std::fixed << std::setprecision(1) << value;
        }
    }
    std::cout << std::endl;
}

bool ScalarConverter::isDisplayable(char c)
{
    return (c >= 32 && c <= 126);
}
