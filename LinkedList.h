/**
 * LinkedList.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "ListIterator.h"
#include <iostream>

template<class T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        clear();
    }

    LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr) {
        copy(other);
    }

   
    LinkedList<T>& operator=(const LinkedList<T>& other) {
        if (this != &other) {
            clear();
            copy(other);
        }
        return *this;
    }

   
    void copy(const LinkedList<T>& other) {
        Node<T> *temp = other.head;
        while (temp != nullptr) {
            append(temp->data);
            temp = temp->next;
        }
    }

   
    void clear() {
        while (head != nullptr) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

   
    bool isEmpty() const {
        return head == nullptr;
    }

   
    void append(const T& newData) {
        Node<T> *newNode = new Node<T>(newData);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

  
    void prepend(const T& newData) {
        Node<T> *newNode = new Node<T>(newData);
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

  
    void remove(const T& target) {
        if (isEmpty()) {
            return;
        }
        if (head->data == target) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
            return;
        }
        Node<T> *prev = head;
        Node<T> *current = head->next;
        while (current != nullptr) {
            if (current->data == target) {
                prev->next = current->next;
                delete current;
                if (prev->next == nullptr) {
                    tail = prev;
                }
                return;
            }
            prev = current;
            current = current->next;
        }
    }

 
    ListIterator<T> begin() const {
        return ListIterator<T>(head);
    }

  
    ListIterator<T> end() const {
        return ListIterator<T>(nullptr);
    }

   
    void print() const {
        Node<T> *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

#endif





