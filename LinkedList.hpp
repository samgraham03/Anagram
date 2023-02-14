#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <string>

template <typename type>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        void insert(const type &data);
        type at(unsigned int i);
        unsigned int length();
    private:
        struct Node {
            Node(const type &data, Node *&next = nullptr) : data(data), next(next) {};
            Node *next;
            type data;
        } *head;
        unsigned int size;
};

template class LinkedList<LinkedList<std::string>>;
#endif