# pragma once

class Node  {
    public:
    int key = 0;
    Node *next = nullptr;
    Node(int key) : key(key) {};
};

class ListaEncadeada {
    Node *head = nullptr;
    int size = 0;
    public:
    ListaEncadeada() = default;

};