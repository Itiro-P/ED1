#include <iterator>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>

template<typename est>
void printEst(const est& element) {
    for(const auto& it: element) {
        std::cout << it << ' ';
    }
    std::cout << '\n';
}

int somaLista(const std::list<int>& lista, const std::list<int>::iterator it, int soma = 0) {
    return (it == lista.end() ? soma : somaLista(lista, std::next(it), soma + *it));
}

bool busca(const std::list<int>& lista, const std::list<int>::iterator it, int valor) {
    return (it == lista.end() ? false : (*it == valor ? true : busca(lista, std::next(it), valor)));
}

void inverteString(std::string& str, std::string::iterator d, std::string::iterator e) {
    (d != e && e != str.begin() ? (*d ^= *e ^= *d ^= *e, inverteString(str, std::next(d), std::prev(e))) : void());
}

double potencia(double base, int expoente, double cur = 1) {
    return (expoente == 0 ? cur : (expoente > 0 ? potencia(base, --expoente, cur * base) : potencia(base, ++expoente, cur * 1/base)));
}

int mdcRecursivo(int a, int b) {
    return(b == 0 ? a : mdcRecursivo(b, b % a));
}

int contaNos(const std::list<int>& lista, const std::list<int>::iterator it, int cur = 0) {
    return (it == lista.end() ? cur : contaNos(lista, std::next(it), ++cur));
}

bool palindromo(const std::string& str, const std::string::iterator d, const std::string::iterator e) {
    return (d != e ? (*d == *e ? palindromo(str, std::next(d), std::prev(e)) : false) : true);
}

int somaDigitos(int numero) {
    return 0;
}

int fibonacci(int n) {
    return (n <= 0 ? 0 : (n > 0 && n <= 3 ? 1: fibonacci(n-1) + fibonacci(n-2)));
}

void imprimeReverso(const std::forward_list<int>& lst, const std::forward_list<int>::iterator it) {
    (it != lst.end() ? imprimeReverso(lst, std::next(it)), std::cout << *it << ' ': std::cout << '\n');
}

int main() {
    std::list<int> lista = {1, 2, 3, 4, 5, 7, 8, 100};
    std::forward_list<int> lista2 = {1, 2, 3, 4, 5, 6};
    std::string teste = "";
    int a = 6;
    int exp = 900;
    imprimeReverso(lista2, lista2.begin());
    return 0;
}
