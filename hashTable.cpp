#include "hashTable.h"

HashTable::HashTable(int size) : tableSize(size), table(size) {}

int HashTable::hash(const std::string& key) {
    int hashValue = 0;
    for (char c : key) {
        hashValue = (hashValue * 31 + c) % tableSize;
    }
    return hashValue;
}

void HashTable::insert(const std::string& key, const std::string& value) {
    int index = hash(key);
    for (auto& kv : table[index]) {
        if (kv.first == key) {
            kv.second = value;
            return;
        }
    }
    table[index].emplace_back(key, value);
}

bool HashTable::search(const std::string& key, std::string& value) {
    int index = hash(key);
    for (auto& kv : table[index]) {
        if (kv.first == key) {
            value = kv.second;
            return true;
        }
    }
    return false;
}

bool HashTable::remove(const std::string& key) {
    int index = hash(key);
    auto& bucket = table[index];
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->first == key) {
            bucket.erase(it);
            return true;
        }
    }
    return false;
}
