#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <climits>
# include <cfloat>
# include <cstdlib>
# include <iomanip>

enum LiteralType
{
    CHAR_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    INVALID_TYPE
};

class ScalarConverter
{
private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter(void);

    static LiteralType detectType(const std::string& literal);
    static bool isChar(const std::string& literal);
    static bool isInt(const std::string& literal);
    static bool isFloat(const std::string& literal);
    static bool isDouble(const std::string& literal);
    static bool isPseudoLiteral(const std::string& literal);

    static void convertFromChar(char c);
    static void convertFromInt(int value);
    static void convertFromFloat(float value);
    static void convertFromDouble(double value);
    static void handlePseudoLiteral(const std::string& literal);

    static void displayChar(char c, bool impossible = false, bool nonDisplayable = false);
    static void displayInt(int value, bool impossible = false);
    static void displayFloat(float value, bool impossible = false);
    static void displayDouble(double value, bool impossible = false);

    static bool isDisplayable(char c);
    static bool isValidNumber(const std::string& literal);

public:
    static void convert(const std::string& literal);
};

#endif
