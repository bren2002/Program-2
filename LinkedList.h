/**
 * LinkedList.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "ListIterator.h"

template <typename T>
class LinkedList {
    Node<T> *head;
    Node<T> *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    bool isEmpty() const { return head == nullptr; }
    void addFirst(const T& data);
    void addLast(const T& data);
    int size() const;
    bool contains(const T& data) const;
    int find(const T& data) const;
    void makeEmpty();
    void addAt(int index, const T& data);
    void removeAt(int index);
    void removeAll(const T& data);
    ListIterator<T> first() const { return ListIterator<T>(head); }
    ListIterator<T> end() const { return ListIterator<T>(nullptr); }
    ~LinkedList();
};

template <typename T>
void LinkedList<T>::addFirst(const T& data) {
    if (isEmpty()) {
        head = tail = new Node<T>(data);
    } else {
        head = new Node<T>(data, head);
    }
}

template <typename T>
void LinkedList<T>::addLast(const T& data) {
    if (isEmpty()) {
        head = tail = new Node<T>(data);
    } else {
        tail->next = new Node<T>(data);
        tail = tail->next;
    }
}

template <typename T>
int LinkedList<T>::size() const {
    int count = 0;
    Node<T> *current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    makeEmpty();
}

template <typename T>
void LinkedList<T>::makeEmpty() {
    while (head != nullptr) {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

#endif
