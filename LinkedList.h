/**
 * LinkedList.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include "ListIterator.h"
#include <stdexcept>

template<class T>
class LinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int currentSize;

public:
    LinkedList() : head(nullptr), tail(nullptr), currentSize(0) {}

    int size() const {
        return currentSize;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void addAt(int index, T obj) {
        if (index < 0 || index > currentSize)
            throw std::runtime_error("Error: addAt bad index");

        if (index == 0) {
            addFirst(obj);
        } else if (index == currentSize) {
            addLast(obj);
        } else {
            Node<T> *newNode = new Node<T>(obj);
            Node<T> *current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            ++currentSize;
        }
    }

    void addFirst(T obj) {
        Node<T> *newNode = new Node<T>(obj);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        ++currentSize;
    }

    void addLast(T obj) {
        Node<T> *newNode = new Node<T>(obj);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        ++currentSize;
    }

    T peekFirst() const {
        if (isEmpty())
            throw std::runtime_error("Error: peekFirst empty list");
        return head->data;
    }

    T peekLast() const {
        if (isEmpty())
            throw std::runtime_error("Error: peekLast empty list");
        return tail->data;
    }

    void removeAt(int index) {
        if (isEmpty())
            throw std::runtime_error("Error: removeAt empty list");
        if (index < 0 || index >= currentSize)
            throw std::runtime_error("Error: removeAt bad index");

        if (index == 0) {
            removeFirst();
        } else if (index == currentSize - 1) {
            removeLast();
        } else {
            Node<T> *current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node<T> *nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete;
            --currentSize;
        }
    }

    T removeFirst() {
        if (isEmpty())
            throw std::runtime_error("Error: removeFirst empty list");
        Node<T> *nodeToDelete = head;
        T dataToReturn = head->data;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        delete nodeToDelete;
        --currentSize;
        return dataToReturn;
    }

    T removeLast() {
        if (isEmpty())
            throw std::runtime_error("Error: removeLast empty list");
        Node<T> *nodeToDelete = tail;
        T dataToReturn = tail->data;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            Node<T> *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = nullptr;
            tail = current;
        }
        delete nodeToDelete;
        --currentSize;
        return dataToReturn;
    }

    int find(T obj) const {
        int index = 0;
        Node<T> *current = head;
        while (current != nullptr) {
            if (current->data == obj) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return -1;
    }

    bool isFull() const {
        return false;
    }

    void makeEmpty() {
        Node<T> *current = head;
        while (current != nullptr) {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        currentSize = 0;
    }

    bool contains(T obj) const {
        return find(obj) != -1;
    }

    bool remove(T obj) {
        if (isEmpty())
            return false;

        if (head->data == obj) {
            removeFirst();
            return true;
        }

        Node<T> *current = head;
        while (current->next != nullptr) {
            if (current->next->data == obj) {
                Node<T> *nodeToDelete = current->next;
                current->next = current->next->next;
                delete nodeToDelete;
                --currentSize;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void removeAll(T obj) {
        while (contains(obj)) {
            remove(obj);
        }
    }

    ListIterator<T> first() const {
        return ListIterator<T>(head);
    }

    ListIterator<T> end() const {
        return ListIterator<T>(nullptr);
    }

    ~LinkedList() {
        makeEmpty();
    }
};

#endif




