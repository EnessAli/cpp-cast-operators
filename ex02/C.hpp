#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class C : public Base
{
public:
    C(void);
    C(const C& src);
    C& operator=(const C& src);
    virtual ~C(void);
};

#endif
