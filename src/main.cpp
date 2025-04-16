#include <listaSequencial.hpp>
#include <listaEncadeada.hpp>
#include <iostream>

int main() {
    ListaEncadeada listaEnc;
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
    listaEnc.insert(9, 100);
    listaEnc.print();
    return 0;
}