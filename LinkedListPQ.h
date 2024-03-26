/**
 * LinkedListPQ.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKED_LIST_PQ_H
#define LINKED_LIST_PQ_H

#include "PriorityQueue.h"
#include "LinkedList.h"

template<class T>
class LinkedListPQ : public PriorityQueue<T> {
private:
    LinkedList<T> pq;

public:
    LinkedListPQ() {}

    void enqueue(const T &element, int priority) override {
        pq.addLast(element);
    }

    T dequeue() override {
        if (isEmpty())
            throw std::runtime_error("Error: dequeue from empty priority queue");
        return pq.removeFirst();
    }

    const T &peek() const override {
        if (isEmpty())
            throw std::runtime_error("Error: peek from empty priority queue");
        return pq.peekFirst();
    }

    bool isEmpty() const override {
        return pq.isEmpty();
    }

    int size() const override {
        return pq.size();
    }

    void clear() override {
        pq.makeEmpty();
    }
};

#endif



