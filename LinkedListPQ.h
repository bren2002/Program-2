/**
 * LinkedListPQ.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKED_LIST_PQ_H
#define LINKED_LIST_PQ_H

#include "PriorityQueue.h"
#include "LinkedList.h"

template<typename T>
class LinkedListPQ : public PriorityQueue<T> {
private:
    LinkedList<T> pq;

public:
    bool insert(T object) override {
        pq.addLast(object);
        return true;
    }

    T remove() override {
        if (pq.isEmpty()) {
            throw std::invalid_argument("Cannot remove from empty queue");
        }
        return pq.removeFirst();
    }
    
    bool deleteAll(T obj) override {
        return pq.remove(obj);
    }

    T peek() override {
        if (pq.isEmpty()) {
            throw std::invalid_argument("Cannot peek from empty queue");
        }
        return pq.peekFirst();
    }

    bool contains(T obj) override {
        return pq.contains(obj);
    } 

    int size() override {
        return pq.size();
    }
    
    void clear() override {
        pq.makeEmpty();
    }

    bool isEmpty() override {
        return pq.isEmpty();
    }

    bool isFull() override {
        return false;
    }
        
    ListIterator<T> first() override {
        return pq.first();
    }

    ListIterator<T> end() override {
        return pq.end();
    }
};

#endif
