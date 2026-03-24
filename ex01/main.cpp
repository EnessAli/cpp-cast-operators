#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== Serialization Test ===" << std::endl;
    
    // Create a Data object
    Data* originalData = new Data(42, "Test Object", 3.14159, true);
    std::cout << "\nOriginal data:" << std::endl;
    originalData->display();
    std::cout << "Original pointer address: " << originalData << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(originalData);
    std::cout << "\nSerialized value: " << serialized << std::endl;
    std::cout << "Serialized value (hex): 0x" << std::hex << serialized << std::dec << std::endl;
    
    // Deserialize back to pointer
    Data* deserializedData = Serializer::deserialize(serialized);
    std::cout << "\nDeserialized pointer address: " << deserializedData << std::endl;
    std::cout << "Deserialized data:" << std::endl;
    deserializedData->display();
    
    // Verify pointers are equal
    std::cout << "\nPointer comparison:" << std::endl;
    std::cout << "Original == Deserialized: " << (originalData == deserializedData ? "true" : "false") << std::endl;
    
    // Test with modified data through deserialized pointer
    std::cout << "\n=== Modifying data through deserialized pointer ===" << std::endl;
    deserializedData->name = "Modified through deserialized pointer";
    deserializedData->value = 2.71828;
    
    std::cout << "Original data after modification:" << std::endl;
    originalData->display();
    std::cout << "Deserialized data after modification:" << std::endl;
    deserializedData->display();
    
    // Test with null pointer
    std::cout << "\n=== Null pointer test ===" << std::endl;
    Data* nullPtr = NULL;
    uintptr_t serializedNull = Serializer::serialize(nullPtr);
    Data* deserializedNull = Serializer::deserialize(serializedNull);
    
    std::cout << "Null pointer serialized: " << serializedNull << std::endl;
    std::cout << "Null pointer deserialized: " << deserializedNull << std::endl;
    std::cout << "Null test passed: " << (nullPtr == deserializedNull ? "true" : "false") << std::endl;
    
    // Clean up
    delete originalData;
    
    std::cout << "\n=== Test completed ===" << std::endl;
    return 0;
}
