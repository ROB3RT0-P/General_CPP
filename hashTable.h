#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <string>

class HashTable {
public:
    HashTable(int size);
    void insert(const std::string& key, const std::string& value);
    bool search(const std::string& key, std::string& value);
    bool remove(const std::string& key);

private:
    int tableSize;
    std::vector<std::list<std::pair<std::string, std::string>>> table;
    int hash(const std::string& key);
};

#endif // HASHTABLE_H