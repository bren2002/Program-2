/**
 * LinkedListPQ.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKEDLISTPQ_H
#define LINKEDLISTPQ_H

#include "LinkedList.h"
#include "ListIterator.h"

template<typename T>
class LinkedListPQ {
private:
    LinkedList<T> list;

public:
    LinkedListPQ() {}

    void enqueue(const T& item) {
        list.append(item); 
    }

    T dequeue() {
        if (list.isEmpty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        T item = list.peekFirst();
        list.removeFirst();
        return item;
    }

    bool isEmpty() const {
        return list.isEmpty();
    }

    int getSize() const {
        return list.getSize();
    }

    ListIterator<T> begin() const {
        return list.begin();
    }

    ListIterator<T> end() const {
        return list.end();
    }
};

#endif

