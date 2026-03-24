#ifndef TYPEIDENTIFIER_HPP
# define TYPEIDENTIFIER_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <exception>

// Function declarations
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
