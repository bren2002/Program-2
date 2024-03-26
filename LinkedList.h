/**
 * LinkedList.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListIterator.h"
#include <stdexcept>

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList();

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void append(const T& item) {
        if (isEmpty()) {
            head = new Node<T>(item);
            tail = head;
        } else {
            tail->next = new Node<T>(item);
            tail = tail->next;
        }
        size++;
    }

    void prepend(const T& item) {
        head = new Node<T>(item, head);
        if (!tail) {
            tail = head;
        }
        size++;
    }

    void insertAt(int index, const T& item) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            prepend(item);
        } else if (index == size) {
            append(item);
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            current->next = new Node<T>(item, current->next);
            size++;
        }
    }

    T removeAt(int index) {
        if (isEmpty() || index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        T removedItem;
        if (index == 0) {
            removedItem = head->data;
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            if (!head) {
                tail = nullptr;
            }
        } else {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node<T>* temp = current->next;
            removedItem = temp->data;
            current->next = temp->next;
            delete temp;
            if (!current->next) {
                tail = current;
            }
        }
        size--;
        return removedItem;
    }

    T getAt(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
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

    ListIterator<T> begin() const {
        return ListIterator<T>(head);
    }

    ListIterator<T> end() const {
        return ListIterator<T>(nullptr);
    }
};

#endif

