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
    Node<T>* next;

    Node(T data) : data(data), next(nullptr) {}
};

#endif
