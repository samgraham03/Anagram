#include "LinkedList.hpp"

template <class type>
LinkedList<type>::LinkedList() : head(nullptr), size(0) {}

template <class type>
LinkedList<type>::~LinkedList() {
    Node *next = this->head;
    while (next != nullptr) {
        Node *node = next;
        next = next->next;
        delete node;
        node = nullptr;
    }
}

template <class type>
type LinkedList<type>::at(unsigned int i) {
    Node *node = this->head;
    for (unsigned int j = 0; j < i; j++) {
        if (!node || !node->next) throw 0;
        node = node->next;
    }
    return node->data;
}

template <class type>
void LinkedList<type>::insert(const type &data) {
    this->head = new Node(data, this->head);
    this->size++;
}

template <class type>
unsigned int LinkedList<type>::length() {
    return this->size;
}