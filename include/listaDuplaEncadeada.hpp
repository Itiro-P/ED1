#pragma once
#include <iostream>


class ListaDuplaEncadeada {
    class Node {
        public:
        int key = 0;
        Node *next = nullptr;
        Node *prev = nullptr;
        Node(int key) : key(key) {};
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    Node *sentinel;
    int _size = 0;
    public:
    ListaDuplaEncadeada();
    ~ListaDuplaEncadeada();
    void push_front(int key);
    bool pop_front();
    bool insert(int pos, int key);
    int get(int pos);
    void print();
    int size();
    bool empty();
    void push_back(int key);
    bool pop_back();
};