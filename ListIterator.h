/**
 * ListIterator.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "Node.h"

template<typename T>
class ListIterator {
private:
    Node<T>* itptr;

public:
    // Constructors
    ListIterator() : itptr(nullptr) {}
    ListIterator(const ListIterator<T>& q) : itptr(q.itptr) {}
    ListIterator(Node<T>* q) : itptr(q) {}

    // Overloaded operators
    ListIterator& operator++ () { 
        itptr = itptr->next;
        return *this;
    }
    ListIterator operator++ (int) { 
        ListIterator<T> tmp = *this; 
        ++(*this); 
        return tmp; 
    }
    bool operator== (const ListIterator<T>& q) const {
        return itptr == q.itptr;
    }
    bool operator!= (const ListIterator<T>& q) const {
        return itptr != q.itptr;
    }
    T& operator* () {
        return itptr->data;
    }
};

#endif

