/**
 * LinkedListPQ.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKEDLISTPQ_H
#define LINKEDLISTPQ_H

#include "LinkedList.h"

template <typename T>
class LinkedListPQ {
    LinkedList<T> list;

public:
    bool isEmpty() const { return list.isEmpty(); }
    bool isFull() const { return false; } // Linked List doesn't have a fixed size
    void insert(const T& data) { list.addLast(data); }
    T peek() const; // Implement according to your priority queue logic
    T remove(); // Implement according to your priority queue logic
    int size() const { return list.size(); }
    bool contains(const T& data) const { return list.contains(data); }
    void deleteAll(const T& data) { list.removeAll(data); }
    void clear() { list.makeEmpty(); }
};

#endif
