#include <listaEncadeada.hpp>

ListaEncadeada::~ListaEncadeada() {
    Node *temp = head;
    while(temp) {
        Node *prox = temp->next;
        Node *temp2 = temp;
        temp = prox;
        delete temp2;
    }
}

void ListaEncadeada::push_front(int key) {
    Node *novo = new Node(key);
    if(novo) {
        novo->next = head;
        head = novo;
        ++_size;
    }
}

bool ListaEncadeada::pop_front() {
    if(!_size) return false;
    Node *temp = head;
    head = head->next;
    delete temp;
    --_size;
    return true;
}
int ListaEncadeada::get(int pos) {
    if(_size && head && pos >  -1 && pos < _size) {
        Node *temp = head;
        for(int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
        return temp->key;
    }
    return -1;
}

void ListaEncadeada::print() {
    Node *temp = head;
    while(temp) {
        std::cout << temp->key << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

int ListaEncadeada::size() {
    return _size;
}

bool ListaEncadeada::empty() {
    return _size == 0;
}

void ListaEncadeada::push_back(int key) {
    if(!_size) {
        head = new Node(key);
    } else {
        Node *temp = head;
        while(temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(key);
    }
    ++_size;
}

bool ListaEncadeada::pop_back() {
    if(!_size) return false;

    if(_size == 1) {
        delete head;
        head = nullptr;
    } else {
        Node *temp = nullptr;
        Node *cur = head;
        while(cur->next) {
            temp = cur;
            cur = cur->next;
        }
        temp->next = nullptr;
        delete cur;
    }
    --_size;
    return true;
}
