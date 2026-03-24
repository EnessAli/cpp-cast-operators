#include "Data.hpp"
#include <iostream>

Data::Data(void) : id(0), name("default"), value(0.0), isActive(false)
{
    std::cout << "Data default constructor called" << std::endl;
}

Data::Data(int id, const std::string& name, double value, bool isActive)
    : id(id), name(name), value(value), isActive(isActive)
{
    std::cout << "Data parameterized constructor called" << std::endl;
}

Data::Data(const Data& src)
    : id(src.id), name(src.name), value(src.value), isActive(src.isActive)
{
    std::cout << "Data copy constructor called" << std::endl;
}

Data& Data::operator=(const Data& src)
{
    std::cout << "Data assignment operator called" << std::endl;
    if (this != &src)
    {
        id = src.id;
        name = src.name;
        value = src.value;
        isActive = src.isActive;
    }
    return *this;
}

Data::~Data(void)
{
    std::cout << "Data destructor called" << std::endl;
}

void Data::display(void) const
{
    std::cout << "Data: [ID: " << id << ", Name: " << name 
              << ", Value: " << value << ", Active: " 
              << (isActive ? "true" : "false") << "]" << std::endl;
}
