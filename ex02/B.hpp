#ifndef B_HPP
# define B_HPP

# include "Base.hpp"

class B : public Base
{
public:
    B(void);
    B(const B& src);
    B& operator=(const B& src);
    virtual ~B(void);
};

#endif
