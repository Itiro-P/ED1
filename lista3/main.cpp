#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

std::vector<int> vet_to_vector(int *v, int n) {
    if(v == nullptr || n <= 0) return std::vector<int>{};

    std::vector<int> res;
    res.reserve(n);
    for(int i = 0; i < n; ++i) res.push_back(v[i]);
    return res;
}

std::list<int> vet_to_list(int *v, int n) {
    if(v == nullptr || n <= 0) return std::list<int>{};

    std::list<int> res;
    for(int i = 0; i < n; ++i) res.push_back(v[i]);
    return res;
}

std::stack<int> vet_to_stack(int *v, int n) {
    if(v == nullptr || n <= 0) return std::stack<int>{};

    std::stack<int> res;
    for(int i = n-1; i <= 0; --i) {
        res.push(v[i]);
    }
    return res;
}

std::vector<int> list_concat(std::list<int> &list1, std::list<int> &list2) {
    std::vector<int> res;
    res.reserve(list1.size() + list2.size());
    for(const auto &it: list1) res.push_back(it);
    for(const auto &it: list2) res.push_back(it);
    return res;
}

bool check_brackets(std::string expression) {
    bool res = false;

    if(expression.size() > 0) {
        std::stack<char> stack;
        for(const auto &it: expression) {
            if(it == '(' || it == '[' || it == '{') {
                stack.push(it);
            } else if(it == ')' || it == ']' || it == '}') {
                if( 
                    !(
                        stack.top() == '(' && it == ')' ||
                        stack.top() == '[' && it == ']' ||
                        stack.top() == '{' && it == '}'
                    )
                ) {
                    res = false;
                    break;                    
                } else if(stack.empty()) {
                    res = false;
                    break;
                } else {
                    stack.pop();
                    res = true;
                }
            }
        }
        if(stack.size() != 0) res = false;
    }
    return res;
}

std::vector<std::string> vectorize_expression(std::string expression) {
    std::vector<std::string> res;
    if(expression.size() > 0) {
        res.reserve(expression.size());
        std::string elem;
        for(const auto &it: expression) {
            if(it == ' ') {
                res.push_back(elem);
                elem.erase();
            } else {
                elem.push_back(it);
            }
        }
        if(elem.size() > 0) res.push_back(elem);
    }
    return res;
}

float calc_posfix(std::string expression) {
    float res = 0.f;
    std::vector<std::string> vecExp;
    if(expression.size() > 0) {
        vecExp.reserve(expression.size());
        std::string elem;
        for(const auto &it: expression) {
            if(it == ' ') {
                vecExp.push_back(elem);
                elem.erase();
            } else {
                elem.push_back(it);
            }
        }
        if(elem.size() > 0) vecExp.push_back(elem);
    }

    if(vecExp.size() > 0) {
        std::stack<float> stack;
        for(const auto &it: vecExp) {
            if(isdigit(it.front())) {
                stack.push(stoi(it));
            } else {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                switch(it.front()) {
                    case '*':
                    stack.push(a*b);
                    break;
                    case '/':
                    stack.push(a/b);
                    break;
                    case '+':
                    stack.push(a+b);
                    break;
                    case '-':
                    stack.push(a-b);
                    break;
                }
            }
        }
        res = stack.top();
    }
    return res;
}

bool check_posfix(std::string expression) {
    bool res = false;
    std::vector<std::string> vecExp;
    if(expression.size() > 0) {
        vecExp.reserve(expression.size());
        std::string elem;
        for(const auto &it: expression) {
            if(it == ' ') {
                vecExp.push_back(elem);
                elem.erase();
            } else {
                elem.push_back(it);
            }
        }
        if(elem.size() > 0) vecExp.push_back(elem);
    }

    if(vecExp.size() > 0) {
        std::stack<int> stack;
        for(const auto &it: vecExp) {
            if(isdigit(it.front())) {
                stack.push(stoi(it));
            } else {
                if(stack.size() >= 2) {
                    stack.pop();
                }
            }
        }
        res = stack.size() == 1;
        while(!stack.empty()) {
            std::cout << stack.top() << '\n';
            stack.pop();
        }
    }
    return res;
}

float calc_infix(std::string expression) {
    std::stack<char> op;
    std::stack<float> num;
    std::string cur;

    for (const auto &it : expression) {
        if (it == ' ') {
            if (!cur.empty()) {
                num.push(std::stoi(cur));
                cur.clear();
            }
        } else if (it == '(') {
            if (!cur.empty()) {
                num.push(std::stoi(cur));
                cur.clear();
            }
            op.push(it);
        } else if (it == ')') {
            if (!cur.empty()) {
                num.push(std::stoi(cur));
                cur.clear();
            }
            while (!op.empty() && op.top() != '(') {
                float second = num.top(); num.pop();
                float first = num.top(); num.pop();
                char Op = op.top(); op.pop();
                float res = 0.f;
                switch(Op) {
                    case '*': 
                    res = first * second;
                    break;
                    case '/': 
                    res =  first / second;
                    break;
                    case '+': 
                    res =  first + second;
                    break;
                    case '-': 
                    res =  first - second;
                    break;
                    default: res = 0.f;
                }
                num.push(res);
            }
            if (!op.empty()) op.pop();
        } else if (it == '*' || it == '/' || it == '+' || it == '-') {
            if (!cur.empty()) {
                num.push(std::stoi(cur));
                cur.clear();
            }
            while (!op.empty() && op.top() != '(' && !(op.top() == '*' || op.top() == '/') && (it == '+' || it == '-')) {
                float second = num.top(); num.pop();
                float first = num.top(); num.pop();
                char Op = op.top(); op.pop();
                float res = 0.f;
                switch(Op) {
                    case '*': 
                    res = first * second;
                    break;
                    case '/': 
                    res =  first / second;
                    break;
                    case '+': 
                    res =  first + second;
                    break;
                    case '-': 
                    res =  first - second;
                    break;
                    default: res = 0.f;
                }
                num.push(res);
            }
            op.push(it);
        } else {
            cur.push_back(it);
        }
    }

    if (!cur.empty()) {
        num.push(std::stoi(cur));
        cur.clear();
    }

    while (!op.empty()) {
        float second = num.top(); num.pop();
        float first = num.top(); num.pop();
        char Op = op.top(); op.pop();
        float res = 0.f;
        switch(Op) {
            case '*': 
            res = first * second;
            break;
            case '/': 
            res =  first / second;
            break;
            case '+': 
            res =  first + second;
            break;
            case '-': 
            res =  first - second;
            break;
            default: res = 0.f;
        }
        num.push(res);
    }

    return num.empty() ? 0 : num.top();
}

std::string posfix_to_infix(std::string expression) {
    if(expression.empty()) return std::string{};
    
    std::stack<int> num;
    std::stack<std::string> exp;
    std::string cur;
    for(const auto &it: expression) {
        if(isdigit(it)) {
            cur.push_back(it);
        } else if(' ' && !cur.empty()) {
            num.push(std::stoi(cur));
            cur.clear();
        } else if(it == '*' || it == '+' || it == '/' || it == '-') {
            if(num.size() >= 2) {
                int second = num.top();
                num.pop();
                int first = num.top();
                num.pop();
                exp.push(std::string("( " + std::to_string(first) + ' ' + it + ' ' + std::to_string(second) + " )"));
            } else if(num.size() == 1) {
                int second = num.top();
                num.pop();
                std::string temp = exp.top();
                exp.pop();
                exp.push(std::string("( " + temp + ' ' + it + ' ' + std::to_string(second) + " )"));
            } else {
                std::string second = exp.top();
                exp.pop();
                std::string first = exp.top();
                exp.pop();
                exp.push(std::string("( " + first + ' ' + it + ' ' + second + " )"));
            }
        }
    }
    return exp.top();
}

/*

    6 9 + 3 / 6 4 - *
    (6 + 9) 3 / 6 4 - *
    ((6 + 9) / 3 ) 6 4 - *
    ((6 + 9) / 3 ) (6 - 4) *
    ((6 + 9) / 3 ) * (6 - 4)


*/

int main() {
    //std::vector<std::string> a = vectorize_expression("24 32 + 2 / 41 5 * +");
    //for(const auto &it: a) std::cout << it << ' ';
    std::cout << calc_posfix("1 2 + 3 / ");
    std::cout << '\n';
}