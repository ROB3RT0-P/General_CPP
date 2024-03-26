#include <iostream>

const int TABLE_SIZE = 10;

struct HashEntry 
{
    int key;
    int value;
    HashEntry* next;

    HashEntry(int key, int value) : key(key), value(value), next(nullptr) {}
};

class HashTable 
{
private:
    HashEntry** table;

    int hashFunction(int key) 
    {
        return key % TABLE_SIZE;
    }

public:
    HashTable() 
    {
        table = new HashEntry*[TABLE_SIZE]();
    }

    void insert(int key, int value) 
    {
        int index = hashFunction(key);
        HashEntry* newNode = new HashEntry(key, value);

        if (!table[index]) 
        {
            table[index] = newNode;
        } else 
        {
            HashEntry* current = table[index];
            while (current->next) 
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int get(int key) 
    {
        int index = hashFunction(key);
        HashEntry* current = table[index];

        while (current) 
        {
            if (current->key == key) 
            {
                return current->value;
            }
            current = current->next;
        }
        return 0;
    }

    ~HashTable() 
    {
        for (int i = 0; i < TABLE_SIZE; ++i) 
        {
            HashEntry* current = table[i];
            while (current) 
            {
                HashEntry* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }
};

int main() 
{
    HashTable ht;

    ht.insert(10, 100);
    ht.insert(20, 200);
    ht.insert(30, 300);

    std::cout << "Value for key 10: " << ht.get(10) << std::endl;
    std::cout << "Value for key 20: " << ht.get(20) << std::endl;
    std::cout << "Value for key 30: " << ht.get(30) << std::endl;
    std::cout << "Value for key 40: " << ht.get(40) << std::endl;

    return 0;
}