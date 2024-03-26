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
private:
    LinkedList<T> list;

public:
    void push(const T& data) {
        list.insert(data);
    }
    
    ListIterator<T> first() {
        return list.first();
    }

    ListIterator<T> end() {
        return list.end();
    }
};

#endif 
