/**
 * LinkedListPQ.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKEDLISTPQ_H
#define LINKEDLISTPQ_H

#include "PriorityQueue.h"
#include "LinkedList.h"

template<class T>
class LinkedListPQ : public PriorityQueue<T> {
private:
    LinkedList<T> list;

public:
    LinkedListPQ() {}

    ~LinkedListPQ() {}

    bool insert(T object) override {
        list.append(object);
        return true;
    }

    T remove() override {
        if (list.isEmpty()) {
            throw std::invalid_argument("Cannot remove from empty queue");
        }
        T highestPriority = list.peekFirst();
        int highestPriorityIndex = 0;
        ListIterator<T> it = list.first();
        int index = 0;
        while (it.hasNext()) {
            T current = it.next();
            if (current < highestPriority) {
                highestPriority = current;
                highestPriorityIndex = index;
            }
            index++;
        }
        return list.removeAt(highestPriorityIndex);
    }

    bool deleteAll(T obj) override {
        bool deleted = false;
        ListIterator<T> it = list.first();
        while (it.hasNext()) {
            if (it.next() == obj) {
                it.remove();
                deleted = true;
            }
        }
        return deleted;
    }

    T peek() override {
        if (list.isEmpty()) {
            throw std::invalid_argument("Cannot peek from empty queue");
        }
        return list.peekFirst();
    }

    bool contains(T obj) override {
        ListIterator<T> it = list.first();
        while (it.hasNext()) {
            if (it.next() == obj) {
                return true;
            }
        }
        return false;
    }

    int size() override {
        return list.getSize();
    }

    void clear() override {
        list.makeEmpty();
    }

    bool isEmpty() override {
        return list.isEmpty();
    }

    bool isFull() override {
        return false; 
    }

    ListIterator<T> first() override {
        return list.begin();
    }

    ListIterator<T> end() override {
        return list.end();
    }
};

#endif


