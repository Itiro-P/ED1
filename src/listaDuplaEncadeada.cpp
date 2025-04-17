#include <listaDuplaEncadeada.hpp>

ListaDuplaEncadeada::ListaDuplaEncadeada() {
    sentinel = new Node(-1);
    tail = head;
}

ListaDuplaEncadeada::~ListaDuplaEncadeada() {
    if(Node *cur = head; cur) {
        while(cur->next != sentinel) {
            Node *temp = cur;
            cur = cur->next;
            delete temp;
        }
        if(sentinel) delete sentinel;
    }
}

void ListaDuplaEncadeada::push_front(int key) {
    Node *newNode = new Node(key);
    if (_size == 0) {
        head = newNode;
        tail = newNode;
        head->next = sentinel;
        head->prev = sentinel;
        sentinel->next = head;
        sentinel->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = sentinel;
        head->prev = newNode;
        sentinel->next = newNode;
        head = newNode;
    }
    ++_size;
}

bool ListaDuplaEncadeada::pop_front() {
    if (_size == 0) return false;

    if (_size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
    } else {
        Node *temp = head;
        head = head->next;
        head->prev = sentinel;
        sentinel->next = head;
        delete temp;
    }
    --_size;
    return true;
}

bool ListaDuplaEncadeada::insert(int pos, int key) {
    if(pos == 0) {
        push_front(key);
        return true;
    }
    else if(pos == _size-1) {
        push_back(key);
        return true;
    }
    else if (pos > 0 && pos < _size-1) {
        Node *nNode = new Node(key);
        Node *cur = head;
        for(int i = 0; i < pos; ++i) {
            cur = cur->next;
        }
        nNode->next = cur->next;
        nNode->prev = cur;
        nNode->next->prev = nNode;
        cur->next = nNode;

        ++_size;
        return true;
    }
    return false;
}

int ListaDuplaEncadeada::get(int pos) {
    if (pos < 0 || pos >= _size) return -1; // Posição inválida

    Node *cur = head;
    for (int i = 0; i < pos; ++i) {
        cur = cur->next;
    }
    return cur->key;
}

void ListaDuplaEncadeada::print() {
    Node *cur = head;
    while(cur != sentinel) {
        std::cout << cur->key << ' ';
        cur = cur->next;
    }
    std::cout << '\n';
}

int ListaDuplaEncadeada::size() {
    return _size;
}

bool ListaDuplaEncadeada::empty() {
    return _size == 0;
}

void ListaDuplaEncadeada::push_back(int key) {
    Node *newNode = new Node(key);
    if (_size == 0) {
        head = newNode;
        tail = newNode;
        head->next = sentinel;
        head->prev = sentinel;
        sentinel->next = head;
        sentinel->prev = head;
    } else {
        newNode->prev = tail;
        newNode->next = sentinel;
        tail->next = newNode;
        sentinel->prev = newNode;
        tail = newNode;
    }
    ++_size;
}

bool ListaDuplaEncadeada::pop_back() {
    if (_size == 0) return false;

    if (_size == 1) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
    } else {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = sentinel;
        sentinel->prev = tail;
        delete temp;
    }
    --_size;
    return true;
}
