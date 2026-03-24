#include "A.hpp"

A::A(void) : Base()
{
}

A::A(const A& src) : Base(src)
{
    *this = src;
}

A& A::operator=(const A& src)
{
    if (this != &src)
    {
        Base::operator=(src);
    }
    return *this;
}

A::~A(void)
{
}
