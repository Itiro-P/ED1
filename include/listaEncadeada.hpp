# pragma once

#include <iostream>

class Node  {
    public:
    int key = 0;
    Node *next = nullptr;
    Node(int key) : key(key) {};
};

class ListaEncadeada {
    Node *head = nullptr;
    int _size = 0;
    public:
    ListaEncadeada() = default;
    ~ListaEncadeada();
    void push_front(int key);
    bool pop_front();
    int get(int pos);
    void print();
    int size();
    bool empty();
    void push_back(int key);
    bool pop_back();
};