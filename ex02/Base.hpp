#ifndef BASE_HPP
# define BASE_HPP

class Base
{
public:
    Base(void);
    Base(const Base& src);
    Base& operator=(const Base& src);
    virtual ~Base(void);
};

#endif
