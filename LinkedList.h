// LinkedList.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include "ListIterator.h"
#include <stdexcept>

/**
 * @class LinkedList
 * 
 * @brief A linked list implementation.
 * 
 * This class represents a linked list data structure.
 * It allows for efficient insertion and removal of elements at both the beginning and end of the list.
 * It also provides methods for accessing and manipulating the elements in the list.
 * 
 * @tparam T The type of elements stored in the list.
 */
template<typename T>
class LinkedList {
private: 
    Node<T> *head;
    Node<T> *tail;
    int currentSize;

public: 
    LinkedList() : head(nullptr), tail(nullptr), currentSize(0) {}

    int size() {
        return currentSize;
    }
            
    bool isEmpty() {
        return head == nullptr;
    }
            
    void addAt(int index, T obj) {
        if (index < 0 || index > currentSize) {
            throw std::runtime_error("Error: addAt bad index");
        }
        Node<T> *newNode = new Node<T>(obj);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) {
                tail = head;
            }
        } else if (index == currentSize) {
            tail->next = newNode;
            tail = newNode;
        } else {
            Node<T> *temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        currentSize++;
    }

    void addFirst(T obj) {
        addAt(0, obj);
    }
        
    void addLast(T obj) {
        addAt(currentSize, obj);
    }
            
    T peekFirst() {
        if (isEmpty()) {
            throw std::runtime_error("Error: peekFirst empty list");
        }
        return head->data;
    }
            
    T peekLast() {
        if (isEmpty()) {
            throw std::runtime_error("Error: peekLast empty list");
        }
        return tail->data;
    }

    void removeAt(int index) {
        if (isEmpty()) {
            throw std::runtime_error("Error: removeAt empty list");
        }
        if (index < 0 || index >= currentSize) {
            throw std::runtime_error("Error: removeAt bad index");
        }
        Node<T> *temp = head;
        if (index == 0) {
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            Node<T> *toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete == tail) {
                tail = temp;
            }
            delete toDelete;
        }
        currentSize--;
    }

    T removeFirst() {
        T data = peekFirst();
        removeAt(0);
        return data;
    }
            
    T removeLast() {
        T data = peekLast();
        removeAt(currentSize - 1);
        return data;
    }

    int find(T obj) {
        int index = 0;
        Node<T> *temp = head;
        while (temp != nullptr) {
            if (temp->data == obj) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }        

    bool isFull() {
        return false;
    }
            
    void makeEmpty() {
        while (!isEmpty()) {
            removeFirst();
        }
    }

    bool contains(T obj) {
        return find(obj) != -1;
    }        
        
    bool remove(T obj) {
        int index = find(obj);
        if (index != -1) {
            removeAt(index);
            return true;
        }
        return false;
    }

    void removeAll(T obj) {
        while (remove(obj));
    }
        
    ListIterator<T> first() {
        return ListIterator<T>(head);
    }

    ListIterator<T> end() {
        return ListIterator<T>(nullptr);
    }
};

#endif
