#include <listaSequencial.hpp>
#include <listaEncadeada.hpp>
#include <iostream>

int main() {
    const int n = 10;
    ListaSequencial listaSeq(n);
    for(int i = 0; i < n; ++i) {
        listaSeq.add(i);
    }
    listaSeq.print();
    listaSeq.remove();
    listaSeq.print();
    listaSeq.remove();
    listaSeq.print();
    listaSeq.insert(9999, 5);
    listaSeq.print();
    listaSeq.addSorted(12);
    listaSeq.print();
    listaSeq.removeAt(0);
    listaSeq.print();
    listaSeq.removeAt(12);
    listaSeq.print();
    listaSeq.removeAt(8);
    listaSeq.print();

    return 0;
}