#include <listaSequencial.hpp>
#include <listaEncadeada.hpp>
#include <listaDuplaEncadeada.hpp>
#include <iostream>

int main() {
    ListaDuplaEncadeada listaEnc;
    int n = 10;
    for(int i = 0; i < n; ++i) {
        listaEnc.push_back(i);    
    }
    listaEnc.print();

    listaEnc.pop_front();
    listaEnc.print();
    listaEnc.pop_back();
    listaEnc.print();
    listaEnc.push_front(999);
    listaEnc.print();
    listaEnc.insert(4, 150);
    listaEnc.print();
    return 0;
}