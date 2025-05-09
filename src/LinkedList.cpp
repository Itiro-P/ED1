#include <LinkedList.hpp>

LinkedList::LinkedList(int arr[], int n) {
    Node **cur = &head;
    _size = n;
    for(int i = 0; i < n; ++i) {
        *cur = new Node(arr[i]);
        cur = &((*cur)->next);
    }
}

LinkedList::~LinkedList()
{
    Node *temp = head;
    while(temp) {
        Node *prox = temp->next;
        Node *temp2 = temp;
        temp = prox;
        delete temp2;
    }
}

void LinkedList::push_front(int key) {
    Node *novo = new Node(key);
    if(novo) {
        novo->next = head;
        head = novo;
        ++_size;
    }
}

bool LinkedList::pop_front() {
    if(!_size) return false;
    Node *temp = head;
    head = head->next;
    delete temp;
    --_size;
    return true;
}

bool LinkedList::insert(int pos, int key) {
    if(pos >= 0 && pos < _size) {
        Node *prev = nullptr, *cur = head;
        for(int i = 0; i < pos; ++i) {
            prev = cur;
            cur = cur->next;
        }
        Node *novo = new Node(key);
        if(prev) prev->next = novo;
        novo->next = cur;
        ++_size;
        if(pos == 0) head = novo;
        return true;
    }
    return false;
}

int LinkedList::get(int pos) {
    if(_size && head && pos >  -1 && pos < _size) {
        Node *temp = head;
        for(int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
        return temp->key;
    }
    return -1;
}

void LinkedList::print() {
    Node *temp = head;
    while(temp) {
        std::cout << temp->key << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

void LinkedList::print_last() {
    Node *cur = head;
    while(cur) {
        if(cur->next) {
            cur = cur->next;
        } else {
            std::cout << cur->key << '\n';
            break;
        }
    }
}

bool LinkedList::is_Sorted() {
    Node *curNode = head;
    int prev = -1, cur = head->key;
    while(curNode) {
        if(prev < cur || prev == -1) {
            prev = cur;
            curNode = curNode->next;
            cur = curNode->key;
        } else {
            return false;
        }
    }
    return true;
}

bool LinkedList::push_back_vector(int n, int *vec) {
    if(n < 1 || vec == nullptr) return false;
    for(int i = 0; i < n; ++i) {
        push_back(vec[n]);
    }
    return true;
}

int LinkedList::size() {
    return _size;
}

bool LinkedList::empty() {
    return _size == 0;
}

void LinkedList::push_back(int key) {
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

bool LinkedList::pop_back() {
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

bool LinkedList::rotate(int n) {
    if(n < _size) {
        Node *cur = head;
        Node *prev = nullptr;
        Node *tail = nullptr;
        Node **curTail = &tail;

        for(int i = 0; i < n; ++i) {
            *curTail = new Node(cur->key);
            curTail = &(*curTail)->next;
            prev = cur;
            cur = cur->next;
            delete prev;
        }
        head = cur;
        while(cur->next) {
            cur = cur->next;
        }
        cur->next = tail;
        return true;
    }
    return false;
}


void LinkedList::reverse() {
    Node *tail = this->head;
    while(tail->next) {
        tail = tail->next;
    }
    Node *cur = head, *index = tail;
    while(cur != tail) {
        index->next = cur;
        cur = cur->next;
        index = index->next;
    }
    this->head = tail;
}

bool LinkedList::sorted() {
    Node *cur = head->next;
    int a = head->key;
    while(cur) {
        if(cur->key >= a) {
            a = cur->key;
        } else {
            return false;
        }
        cur = cur->next;
    }
    return true;
}