#include "TypeIdentifier.hpp"

int main(void)
{
    std::cout << "=== Type Identification Test ===" << std::endl;
    
    // Test multiple generations and identifications
    for (int i = 0; i < 10; i++)
    {
        std::cout << "\n--- Test " << (i + 1) << " ---" << std::endl;
        
        // Generate random object
        Base* randomObject = generate();
        
        if (randomObject == NULL)
        {
            std::cout << "Error: Failed to generate object" << std::endl;
            continue;
        }
        
        // Identify using pointer
        identify(randomObject);
        
        // Identify using reference
        identify(*randomObject);
        
        // Clean up
        delete randomObject;
    }
    
    std::cout << "\n=== Manual Type Tests ===" << std::endl;
    
    // Test each type specifically
    std::cout << "\n--- Creating A object ---" << std::endl;
    Base* objA = new A();
    identify(objA);
    identify(*objA);
    delete objA;
    
    std::cout << "\n--- Creating B object ---" << std::endl;
    Base* objB = new B();
    identify(objB);
    identify(*objB);
    delete objB;
    
    std::cout << "\n--- Creating C object ---" << std::endl;
    Base* objC = new C();
    identify(objC);
    identify(*objC);
    delete objC;
    
    // Test null pointer handling
    std::cout << "\n--- Null pointer test ---" << std::endl;
    Base* nullPtr = NULL;
    identify(nullPtr);
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}
