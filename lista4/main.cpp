#include <iostream>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>

void print_rec(int count, const char* text) {
    if(count < 10) {
        std::cout << text << '\n';
        print_rec(++count, text);
    } else return;
}

void print_txt(char* text) {
    int count = 0;
    print_rec(count, text);
}

void count(int num) {
    if(num <= 50) {
        std::cout << num << '\n';
        count(++num);
    } else return;
}

void count_max(int num, const int max) {
    if(num <= max) {
        std::cout << num << '\n';
        count_max(++num, max);
    } else return;
}

void print_vec(std::vector<int>& vec, int idx) {
    if(vec.empty()) return;

    if(idx < vec.size()) {
        std::cout << vec[idx] << ' ';
        print_vec(vec, ++idx);
    } else {
        std::cout << '\n';
        return;
    }
}

void print_even(std::vector<int>& vec, int idx) {
    if(vec.empty()) return;

    if(idx >= 0) {
        if(!(vec[idx] & 1)) std::cout << vec[idx] << ' ';
        print_even(vec, --idx);
    } else {
        std::cout << '\n';
        return;
    }
}

void print_list(std::list<int>& lst, std::list<int>::iterator& it) {
    if(lst.empty()) return;

    if(it != lst.end()) {
        std::cout << *it << ' ';
        print_list(lst, ++it);
    } else {
        std::cout << '\n';
        return;
    }
}

void print_rev(std::forward_list<int>& lst, std::forward_list<int>::iterator& it) {
    if(it == lst.end()) return;

    int cur = *it;
    print_rev(lst, ++it);
    std::cout << cur << ' ';
}

void remove_all(std::vector<int>& vec) {
    if(vec.empty()) return;
    vec.pop_back();
    remove_all(vec);
}

void print_stack(std::stack<int>& stk) {
    if(stk.empty()) return;
    std::cout << stk.top() << ' ';
    stk.pop();
    print_stack(stk);
}

void push_to(std::stack<int>& stk1, std::stack<int>& stk2) {
    if(stk1.empty()) return;
    stk2.emplace(stk1.top());
    stk1.pop();
    push_to(stk1, stk2);
}

void copy_vector(std::vector<int>& vec1, int idx, std::vector<int>& vec2) {
    if(idx == vec1.size()) return;

    vec2.push_back(vec1[idx]);
    copy_vector(vec1, ++idx, vec2);
}

void copy_list(std::list<int>& lst1, std::list<int>::iterator& it, std::list<int>& lst2) {
    if(it == lst1.end()) return;
    lst2.emplace_back(*it);
    copy_list(lst1, ++it, lst2);
}

int main() {
    std::forward_list<int> a = {0, 1, 2, 3};
    auto it = a.begin();
    print_rev(a, it);
    return 0;
}