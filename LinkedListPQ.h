/**
 * LinkedListPQ.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKED_LIST_PQ_H
#define LINKED_LIST_PQ_H

#include "PriorityQueue.h"
#include <stdexcept>
#include <iostream> // Include iostream for std::ostream

template <typename T>
class LinkedListPQ : public PriorityQueue<T> {
public:
    LinkedListPQ();
    ~LinkedListPQ();
    void insert(const T& data, int priority);
    T removeMin();
    bool isEmpty() const;

protected:
    void print(std::ostream& os) const override;

private:
    struct Node {
        T data;
        int priority;
        Node* next;

        Node(const T& d, int p, Node* n) : data(d), priority(p), next(n) {}
    };

    Node* m_front;
};

template <typename T>
LinkedListPQ<T>::LinkedListPQ() : m_front(nullptr) {}

template <typename T>
LinkedListPQ<T>::~LinkedListPQ() {
    while (m_front) {
        Node* next = m_front->next;
        delete m_front;
        m_front = next;
    }
}

template <typename T>
void LinkedListPQ<T>::insert(const T& data, int priority) {
    if (!m_front || priority < m_front->priority) {
        m_front = new Node(data, priority, m_front);
    } else {
        Node* prev = m_front;
        Node* curr = m_front->next;
        while (curr && priority >= curr->priority) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = new Node(data, priority, curr);
    }
}

template <typename T>
T LinkedListPQ<T>::removeMin() {
    if (isEmpty()) {
        throw std::logic_error("Priority queue is empty");
    }
    T data = m_front->data;
    Node* temp = m_front;
    m_front = m_front->next;
    delete temp;
    return data;
}

template <typename T>
bool LinkedListPQ<T>::isEmpty() const {
    return !m_front;
}

template <typename T>
void LinkedListPQ<T>::print(std::ostream& os) const {
    Node* curr = m_front;
    os << "Priority Queue (Lowest Priority to Highest Priority): ";
    while (curr) {
        os << "(" << curr->data << ", " << curr->priority << ") ";
        curr = curr->next;
    }
    os << std::endl;
}

#endif 

