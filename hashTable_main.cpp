#include "hashTable.h"
#include <iostream>

int main() {
    HashTable robsHashTable(10);

    robsHashTable.insert("Rob", "P");
    robsHashTable.insert("John", "Johnson");
    robsHashTable.insert("Bob", "Smith");

    std::string value;

    if (robsHashTable.search("John", value)) 
    {
        std::cout << "Last name is " << value << std::endl;
    } else 
    {
        std::cout << "Not found in the table." << std::endl;
    }

    if (robsHashTable.remove("Alice")) 
    {
        std::cout << "Removed from the table." << std::endl;
    } else 
    {
        std::cout << "Not found in the table." << std::endl;
    }

    if (robsHashTable.search("Alice", value)) 
    {
        std::cout << "Last name is " << value << std::endl;
    } else 
    {
        std::cout << "Not found in the table." << std::endl;
    }

    return 0;
}
