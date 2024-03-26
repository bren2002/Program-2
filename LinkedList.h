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
    struct Node {
        T data;
        Node* next;

        Node(const T& newData, Node* newNext = nullptr) : data(newData), next(newNext) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        makeEmpty();
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void addLast(const T& item) {
        if (isEmpty()) {
            head = tail = new Node(item);
        } else {
            tail->next = new Node(item);
            tail = tail->next;
        }
        size++;
    }

    void addFirst(const T& item) {
        head = new Node(item, head);
        if (!tail) {
            tail = head;
        }
        size++;
    }

    void addAt(int index, const T& item) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            addFirst(item);
        } else if (index == size) {
            addLast(item);
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            current->next = new Node(item, current->next);
            size++;
        }
    }

    T removeFirst() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        T removedItem = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (!head) {
            tail = nullptr;
        }
        size--;
        return removedItem;
    }

    T removeLast() {
        if (isEmpty()) {
            throw std::runtime_error("List is empty");
        }
        T removedItem;
        if (head == tail) {
            removedItem = head->data;
            delete head;
            head = tail = nullptr;
        } else {
            Node
            removedItem = tail->data;
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        size--;
        return removedItem;
    }

    bool contains(const T& item) const {
        Node* current = head;
        while (current) {
            if (current->data == item) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int find(const T& item) const {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == item) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; // Not found
    }

    void removeAll(const T& item) {
        Node* current = head;
        Node* prev = nullptr;
        while (current) {
            if (current->data == item) {
                if (prev) {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                } else {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                    current = head;
                }
                size--;
            } else {
                prev = current;
                current = current->next;
            }
        }
        tail = prev;
    }

    void makeEmpty() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }

    T getAt(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = head;
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

    ListIterator<T> first() const {
        return ListIterator<T>(head);
    }

    ListIterator<T> end() const {
        return ListIterator<T>(nullptr);
    }


};

#endif
