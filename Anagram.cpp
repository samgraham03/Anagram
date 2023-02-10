#include "Anagram.hpp"

// O(1) time
Anagram::Anagram() : hashTable(nullptr) {}

// O(1) time
Anagram::~Anagram() {
    delete[] this->hashTable;
}

// O(1) time
unsigned int Anagram::hash(const int c) { // Type casting char to int
    // ASCII a-z => Decimal [97, 122] ; ASCII A-Z => Decimal [65, 90]
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return (c % 32) - 1;
    }
    throw std::invalid_argument("Found non-[a-z][A-Z] char");
}

// O(1) time
void Anagram::charTracker(const unsigned int hash, int &tally, int add = +1) {
    // Tally - Running count of non-zero terms in hashTable
    if (this->hashTable[hash] != 0 && (this->hashTable[hash] += add) == 0) // !0 -> 0
        tally--;
    else if (this->hashTable[hash] == 0 && (this->hashTable[hash] += add) != 0) // 0 -> !0
        tally++;
}

// O(n) time : n = string length (or n = 1 if empty string)
bool Anagram::compare(const std::string &str1, const std::string &str2) {
    if (str1.length() == 0 || str1.length() == 0)
        throw std::invalid_argument("0 length string");
    if (str1.length() != str2.length())
        throw std::invalid_argument("Strings not of same length");

    int tally = 0;
    this->hashTable = new int[26]{0};

    for (size_t i = 0; i < str1.length(); i++) {
        this->charTracker(this->hash(str1.at(i)), tally, +1); // String 1
        this->charTracker(this->hash(str2.at(i)), tally, -1); // String 2
    }

    delete[] this->hashTable;
    this->hashTable = nullptr;

    return tally == 0;
}