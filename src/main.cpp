#include <ListSeq.hpp>
#include <LinkedList.hpp>
#include <listaDuplaEncadeada.hpp>
#include <iostream>

int main() {
    LinkedList listaEnc((int[]){1,2,3,4,5,6}, 6);
    ListSeq listaSeq(&listaEnc);
    if(listaSeq.print()) std::cout << "sucesso.\n";
    return 0;
}