/**
 * ListIterator.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "Node.h"

template<typename T>
class ListIterator {

private:
    Node<T> *current;

public:
    ListIterator(Node<T> *start) : current(start) {}

    T operator*() {
        return current->data;
    }

    ListIterator<T>& operator++() {
        current = current->next;
        return *this;
    }

    bool operator!=(const ListIterator<T>& other) {
        return current != other.current;
    }
};

#endif
