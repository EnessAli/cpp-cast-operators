#include "B.hpp"

B::B(void) : Base()
{
}

B::B(const B& src) : Base(src)
{
    *this = src;
}

B& B::operator=(const B& src)
{
    if (this != &src)
    {
        Base::operator=(src);
    }
    return *this;
}

B::~B(void)
{
}
