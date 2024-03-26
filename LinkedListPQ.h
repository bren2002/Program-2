/**
 * LinkedListPQ.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKEDLISTPQ_H
#define LINKEDLISTPQ_H

#include "PriorityQueue.h"
#include "LinkedList.h"
#include <stdexcept> // Include <stdexcept> for std::runtime_error

template<typename T>
class LinkedListPQ : public PriorityQueue<T> {
public:
    LinkedListPQ();
    ~LinkedListPQ();
    bool insert(const T& data, int priority) override;
    T remove() override;
    void print(std::ostream& os) const override; 
    bool deleteAll(const T& obj) override;
    T peek() override;
    bool contains(const T& obj) override;
    int size() override;
    void clear() override;
    bool isEmpty() override;
    bool isFull() override;
    ListIterator<T> first() override;
    ListIterator<T> end() override;

private:
    LinkedList<T> list;
};

template<typename T>
LinkedListPQ<T>::LinkedListPQ() {}

template<typename T>
LinkedListPQ<T>::~LinkedListPQ() {}

template<typename T>
bool LinkedListPQ<T>::insert(const T& data, int priority) {
    list.addLast(data);
    return true;
}

template<typename T>
T LinkedListPQ<T>::remove() {
    if (list.isEmpty()) {
        throw std::runtime_error("Error: cannot remove from an empty priority queue");
    }
    return list.removeFirst();
}

template<typename T>
void LinkedListPQ<T>::print(std::ostream& os) const {
    os << "Priority Queue: ";
    list.print(os);
}

template<typename T>
bool LinkedListPQ<T>::deleteAll(const T& obj) {
    return list.deleteAll(obj);
}

template<typename T>
T LinkedListPQ<T>::peek() {
    if (list.isEmpty()) {
        throw std::runtime_error("Error: cannot peek an empty priority queue");
    }
    return list.peekFirst();
}

template<typename T>
bool LinkedListPQ<T>::contains(const T& obj) {
    return list.contains(obj);
}

template<typename T>
int LinkedListPQ<T>::size() {
    return list.size();
}

template<typename T>
void LinkedListPQ<T>::clear() {
    list.clear();
}

template<typename T>
bool LinkedListPQ<T>::isEmpty() {
    return list.isEmpty();
}

template<typename T>
bool LinkedListPQ<T>::isFull() {

    return false;
}

template<typename T>
ListIterator<T> LinkedListPQ<T>::first() {
    return list.first();
}

template<typename T>
ListIterator<T> LinkedListPQ<T>::end() {
    return list.end();
}

#endif

