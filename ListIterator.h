/**
 * ListIterator.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "Node.h"

template <typename T>
class ListIterator {
private:
    Node<T>* current;

public:
    ListIterator() : current(nullptr) {} 

    ListIterator(Node<T>* start) : current(start) {}

    ListIterator<T>& operator++() {
        if (current) {
            current = current->next;
        }
        return *this;
    }

    T& operator*() const {
        return current->data;
    }

    bool operator==(const ListIterator<T>& other) const {
        return current == other.current;
    }

    bool operator!=(const ListIterator<T>& other) const {
        return !(*this == other);
    }
};

#endif
