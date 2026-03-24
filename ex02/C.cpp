#include "C.hpp"

C::C(void) : Base()
{
}

C::C(const C& src) : Base(src)
{
    *this = src;
}

C& C::operator=(const C& src)
{
    if (this != &src)
    {
        Base::operator=(src);
    }
    return *this;
}

C::~C(void)
{
}
