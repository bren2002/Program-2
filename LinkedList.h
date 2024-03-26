/**
 * LinkedList.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

template<typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(const T& item, Node<T>* nextNode = nullptr) : data(item), next(nextNode) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList();

    bool isEmpty() const;
    int getSize() const;
    void append(const T& item);
    void prepend(const T& item);
    void insertAt(int index, const T& item);
    T removeAt(int index);
    T getAt(int index) const;

    bool isFull() const {
        return false; 
    }

    T peekFirst() const {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        return head->data;
    }

    T peekLast() const {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        return tail->data;
    }

    void removeFirst() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        if (!head) {
            tail = nullptr;
        }
        size--;
    }

    void removeLast() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        size--;
    }
};

#endif
