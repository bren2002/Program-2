/**
 * ListIterator.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LISTITERATOR_H
#define LISTITERATOR_H

template <typename T>
class Node;

template <typename T>
class ListIterator {
    Node<T> *current;

public:
    ListIterator(Node<T> *start) : current(start) {}
    T operator*() const { return current->data; }
    ListIterator<T>& operator++() {
        current = current->next;
        return *this;
    }
    bool operator!=(const ListIterator<T>& other) const {
        return current != other.current;
    }
};

#endif
