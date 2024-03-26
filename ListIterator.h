/**
 * ListIterator.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "Node.h"

template<class T>
class ListIterator {
private:
    Node<T> *currentNode;

public:
    ListIterator(Node<T> *startNode) : currentNode(startNode) {}

    ListIterator<T> &operator++() {
        if (currentNode != nullptr)
            currentNode = currentNode->next;
        return *this;
    }

    ListIterator<T> operator++(int) {
        ListIterator<T> temp = *this;
        ++(*this);
        return temp;
    }

    T &operator*() const {
        if (currentNode == nullptr)
            throw std::runtime_error("Error: dereference of end iterator");
        return currentNode->data;
    }

    bool operator==(const ListIterator<T> &other) const {
        return currentNode == other.currentNode;
    }

    bool operator!=(const ListIterator<T> &other) const {
        return !(*this == other);
    }
};

#endif


