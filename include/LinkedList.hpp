# pragma once

#include <iostream>

class Node  {
    public:
    int key = 0;
    Node *next = nullptr;
    Node(int key) : key(key) {};
};

class LinkedList {
    int _size = 0;
    public:
    Node* head = nullptr;
    LinkedList() = default;
    LinkedList(int arr[], int n);
    ~LinkedList();
    void push_front(int key);
    bool pop_front();
    bool insert(int pos, int key);
    int get(int pos);
    void print();
    void print_last();
    bool is_Sorted();
    bool push_back_vector(int n, int *vec);
    int size();
    bool empty();
    void push_back(int key);
    bool pop_back();
    bool rotate(int n);
    bool sorted();
    void reverse();
};