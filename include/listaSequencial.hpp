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

    // Retorna posições livres no vetor.
    int list_get_available();

    // Remove todos os elementos.
    void list_clear();

    // Remove os n últimos ou o máximo possível.
    void list_remove_last(int n);

    // Imprime em ordem decrescente de posição.
    void list_print_reverse();

    // Adiciona elemntos de outra lista enquanto houver capacidade para tal.
    void list_add(int n, int* vet);

    // Retorna 'true' se a Lista estiver ordenada.
    bool list_is_sorted();

    // Reverte as ordem dos elementos na lista.
    void list_reverse();

    // Retorna 'true' se duas Listas são iguais.
    bool list_equal(ListaSequencial *outra);

    // Concatena com outra Lista obedecendo a capacidade originial.
    int list_concat(ListaSequencial* list2);
};