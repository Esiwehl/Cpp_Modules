#include <iostream>
#include "Serializer.hpp"

// https://www.rapidtables.com/convert/number/hex-to-decimal.html?x=16AFBB298

int main() {
    Data originalData;
    originalData.id = 42;
    originalData.str = "Example";

    uintptr_t serialized = Serializer::serialize(&originalData);

    // Deserialize it back to a pointer
    Data* deserializedData = Serializer::deserialize(serialized);

    std::cout << "address of ogData = " << &originalData << "\n";
    std::cout << "Serialized uint val = " << serialized << "\n";
    std::cout << "deserialized pointer = " << deserializedData << std::endl;

    // Display results
    std::cout << "Original Data ID: " << originalData.id << ", str: " << originalData.str << std::endl;
    std::cout << "Deserialized Data ID: " << deserializedData->id << ", str: " << deserializedData->str << std::endl;

    // Check if the original and deserialized data pointers are the same
    std::cout << "The pointers are " << ((&originalData == deserializedData) ? "" : "not ") << "the same." << std::endl;

    return 0;
}
