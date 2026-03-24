#include "Base.hpp"

Base::Base(void)
{
}

Base::Base(const Base& src)
{
    *this = src;
}

Base& Base::operator=(const Base& src)
{
    if (this != &src)
    {
    }
    return *this;
}

Base::~Base(void)
{
}
