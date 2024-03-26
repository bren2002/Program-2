/**
 * Node.h
 * Brendan Scharmann, 825291656
 * March 25, 2024
 */

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(const T& newData, Node<T> *nextNode = nullptr) : data(newData), next(nextNode) {}
};

#endif

