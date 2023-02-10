#ifndef ANAGRAM_HPP
#define ANAGRAM_HPP

#include <stdexcept>
#include <string>

class Anagram {
    public:
        Anagram();
        ~Anagram();
        bool compare(const std::string &str1, const std::string &str2);

    private:
        unsigned int hash(const int c);
        void charTracker(const unsigned int hash, int &tally, int add);
        int *hashTable;
};

#endif