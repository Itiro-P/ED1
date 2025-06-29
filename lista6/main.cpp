#include <iostream>
#include <unordered_set>
#include <vector>
#include <utility>
#include <string>
#include <list>
#include <forward_list>
#include <queue>
#include <stack>

double potencia(double a, int b) {
    return b == 0 ? 1 : a * (b > 0 ? potencia(a, b - 1) : 1 / potencia(a, -b));
}

int mdc(int a, int b) {
    return b == 0 ? a : mdc(b, a % b);
}

bool binary_search(const std::vector<int>& vec, int target, int left, int right) {
    return (left <= right ? (vec[left + (right-left)/2] == target ? true : vec[left + (right-left)/2] > target ? binary_search(vec, target, left, left + (right-left)/2 - 1) : binary_search(vec, target, left + (right-left)/2 + 1, right)) : false);
}

int soma_digitos(const int n) {
    return n <= 0 ? 0 : n % 10 + soma_digitos(n / 10);
}

std::unordered_set<std::string> permutacoes(std::string& str, size_t left = 0, size_t cur = 0) {
    if(left >= str.size()) return std::unordered_set<std::string>{};
    if(cur >= str.size()) return permutacoes(str, ++left, 0);
    std::string toSwap = str;
    std::swap(toSwap[left], toSwap[cur]);
    std::unordered_set<std::string> swapped = permutacoes(str, left, ++cur);
    swapped.insert(toSwap);
    return swapped;
}

std::vector<std::vector<int>> subconjuntos(std::vector<int>& vec, size_t left = 0, size_t cur = 0) {
    if(left >= vec.size()) return std::vector<std::vector<int>>{};
    if(cur >= vec.size()) return subconjuntos(vec, ++left, 0);
    std::vector<int> toSwap = vec;
    std::swap(toSwap[left], toSwap[cur]);
    std::vector<std::vector<int>> swapped = subconjuntos(vec, left, ++cur);
    swapped.push_back(toSwap);
    return swapped;
}

enum POSICAO {
    VAZIO,
    RAINHA
};

/*
 * - *
 - - -
 * - *
*/



void reverte_string(std::string& str, std::string::iterator d, std::string::iterator e) {
    (d < e ? (*d != *e ? std::swap(*d, *e), reverte_string(str, std::next(d), std::prev(e)) : reverte_string(str, std::next(d), std::prev(e))) : void());
}

int combinacoes(int n, int k) {
    return (n <= 0 ? 1 : (k == 0 || k == n ? 1 : combinacoes(n - 1, k - 1) + combinacoes(n - 1, k)));
}

bool palindromo(std::string& str, std::string::iterator d, std::string::iterator e) {
    return (*d != *e ? false : (d >= e ? true : palindromo(str, std::next(d), std::prev(e))));
}

bool sorted(const std::vector<int>& vec, int i = 0) {
    return (i >= vec.size()-1 ? true : (vec[i] <= vec[i + 1] && sorted(vec, ++i)));
}

template <typename T>
void print(T&& it) {
    for(const auto& elem : it) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cout << sorted({1, 2, 3}) << '\n';
    std::cout << sorted({1, 3, 2}) << '\n';

    return 0;
}
