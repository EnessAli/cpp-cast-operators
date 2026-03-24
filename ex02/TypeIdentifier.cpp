#include "TypeIdentifier.hpp"

Base* generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int randomChoice = std::rand() % 3;
    
    switch (randomChoice)
    {
        case 0:
            std::cout << "Generated type A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated type B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated type C" << std::endl;
            return new C();
        default:
            return new A();
    }
}

void identify(Base* p)
{
    if (p == NULL)
    {
        std::cout << "Error: Null pointer" << std::endl;
        return;
    }
    
    std::cout << "Identifying via pointer: ";
    
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    std::cout << "Identifying via reference: ";
    
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception&)
    {
    }
    
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::exception&)
    {
    }
    
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::exception&)
    {
    }
    
    std::cout << "Unknown type" << std::endl;
}
