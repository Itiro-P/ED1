#pragma once

#include <iostream>

// Lista Sequencial.
class ListaSequencial {
    public:
    // Elementos alocados na Lista Sequencial.
    int size = 0;

    // Capacidade máxima da Lista Sequencial.
    int capacity = 0;

    // Endereço do vetor na heap.
    int *data = nullptr;

    // Construtor da lista.
    ListaSequencial(int _capacity);

    // Destrói o vetor.
    void destroy();

    // Realoca o vetor.
    bool resize();

    // Imprime o conteúdo da Lista Sequencial.
    bool print();

    // Retorna a posição do elemento ou -1.
    int find(int elem);

    // Obtém o elemento na posição especificada ou -1.
    int get(int pos);

    // Retorna 'true' se a Lista estiver vazia.
    bool isEmpty();

    // Retorna 'true' se  a Lista estiver cheia.
    bool isFull();

    // Insere elemento no final da Lista.
    bool add(int elem);

    // Remove elemento do fim da Lista.
    bool remove();

    // Insere elemento na posição especificada.
    void insert(int elem, int pos);

    // Remove elemento na posição especificada.
    void removeAt(int pos);

    // Insere elemento em ordem crescente.
    bool addSorted(int elem);
};