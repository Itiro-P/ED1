#include <iostream>
#include <vector>
#include <list>
int sum(std::vector<int>& vec, int n = 0) {
    return (n < 0 || n >= vec.size() ? 0: vec[n] + sum(vec, n+1));
}

int product(std::list<int>& lst, std::list<int>::iterator it) {
    return (it == lst.end() ? 1: *it  * product(lst, std::next(it)));
}

int min(std::vector<int>& vec, int n = 0) {
    return (vec.size() <= 0 || n < 0 ? -1: (n >= vec.size() ? 2147483647: vec[n] < min(vec, n+1) ? vec[n]: min(vec, n+1)));
}

int min(std::list<int>& lst, std::list<int>::iterator it) {
    return (it == lst.end() ? 2147483647: (*it < min(lst, std::next(it)) ? *it: min(lst, std::next(it))));
}

bool find(std::vector<int>& vec, int elem, int n = 0) {
    return (n >= vec.size()|| n < 0 ? false: vec[n] == elem ? true: find(vec, elem, ++n));
}

int count(std::vector<int>& vec, int elem, int n = 0) {
    return (n >= vec.size()||n < 0 ? 0: (vec[n] == elem ? count(vec, elem, ++n) + 1: count(vec, elem, ++n)));
}

void reverse(std::vector<int>& vec, int first, int last) {
    (first < last && first >= 0 && last < vec.size()) ? (vec[first] == vec[last] ? reverse(vec, ++first, --last): (vec[first] ^= vec[last] ^= vec[first] ^= vec[last], reverse(vec, ++first, --last))) : void();
}

void reverse(std::list<int>& lst, std::list<int>::iterator first, std::list<int>::iterator last) {
    (first != last && last != lst.end()) ? (*first == *last ? reverse(lst, std::next(first), std::prev(last)): (*first ^= *last ^= *first ^= *last, reverse(lst, std::next(first), std::prev(last)))) : void();
}

bool palindrome(std::string& str, int first, int last) {
    return (first < last ? (str[first] != str[last] ? false: palindrome(str, ++first, --last)): true);
}

bool palindrome(std::list<int>& lst, std::list<int>::iterator first, std::list<int>::iterator last) {
    return (first != last && last != lst.end() ? (*first != *last ? false: palindrome(lst, std::next(first), std::prev(last))): true);
}

// função para printar elementos de uma estrutura
template<typename estrutura>
void printv(estrutura&& e) {
    for(const auto &it: e) std::cout << it << ' ';
    std::cout << '\n';
}

int main() {
    std::string testestr = "abab";
    std::vector<int> testevec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> testelst = {13, -1, 2, 3, 4, 3, 2, -1, 13};
    printv(testelst);
    std::cout << palindrome(testelst, testelst.begin(), std::prev(testelst.end())) << '\n';
    return 0;
}
