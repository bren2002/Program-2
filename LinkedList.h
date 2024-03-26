/**
 * LinkedList.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListIterator.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    ListIterator<T> first() {
        return ListIterator<T>(head);
    }

    ListIterator<T> end() {
        return ListIterator<T>(nullptr);
    }

    ~LinkedList() {
        Node<T>* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
