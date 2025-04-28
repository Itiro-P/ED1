#include <listaSequencial.hpp>
#include <listaEncadeada.hpp>
#include <listaDuplaEncadeada.hpp>
#include <iostream>

int main() {
    ListaEncadeada listaEnc((int[5]){1,2,4,5,6}, 5);
    listaEnc.print();
    listaEnc.rotate(4);
    listaEnc.print();
    return 0;
}