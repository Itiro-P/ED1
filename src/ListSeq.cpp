#include <ListSeq.hpp>

ListSeq::ListSeq(int _capacity) {
    data = new int[_capacity];
    if(data) capacity = _capacity;
}

ListSeq::ListSeq(LinkedList *lista) {
    Node *cur = lista->head;
    int size = 0;
    while(cur) {
        ++size;
        cur = cur->next;
    }
    data = new int[size];
    cur = lista->head;
    for(int i = 0; i < size; ++i) {
        data[i] = cur->key;
        cur = cur->next;
    }
    this->size = size;
}

void ListSeq::destroy() {
    if(data) {
        delete[] data;
        size = 0;
        capacity = 0;
        data = nullptr;
    }
}

bool ListSeq::resize() {
    if(data) {
        int *temp = data;
        data = new int[capacity+1];
        if(data) {
            for(int i = 0; i < size; ++i) {
                data[i] = temp[i];
            }
            ++capacity;
            delete[] temp;
            return true;
        }
        data = temp;
    }
    return false;
}

bool ListSeq::print() {
    if(data) {
        for(int i = 0; i < size; ++i) {
            std::cout << data[i] << ' ';
        }
        std::cout << '\n';
    }
    return true;
}

int ListSeq::find(int elem) {
    if(data) for(int i = 0; i < size; ++i) if(data[i] == elem) return i;
    return -1;
}

int ListSeq::get(int pos) {
    if(data && pos < size) return data[pos];
    return -1;
}

bool ListSeq::isEmpty() {
    return size == 0;
}

bool ListSeq::isFull() {
    return size == capacity;
}

bool ListSeq::add(int elem) {
    if(data) {
        if(size < capacity) {
            data[size++] = elem;
            return true;
        } 
        else if(resize()) {
            data[size++] = elem;
            return true;
        }
    }
    return false;
}

bool ListSeq::remove() {
    if(size <= 0) return false;
    --size;
    return true;
}

void ListSeq::insert(int elem, int pos) {
    if(data && pos < size && pos >= 0 && (size < capacity || resize())) {
        for(int i = size; i > pos; --i) data[i] = data[i-1];
        data[pos] = elem;
        ++size;
    }
}

void ListSeq::removeAt(int pos) {
    if(data && pos >= 0 && pos < size) {
        for(int i = pos; i < size; ++i) {
            data[i] = data[i+1];
        }
        --size;
    }
}

bool ListSeq::addSorted(int elem) {
    for(int i = 0; i < size; ++i) {
        if(data[i] < elem) {
            insert(elem, i+1);
            return true;
        }
    }
    return false;
}

int ListSeq::list_get_available() {
    return (capacity-size >= 0 ? capacity-size: 0);
}

void ListSeq::list_clear() {
    size = 0;
}

void ListSeq::list_remove_last(int n) {
    if(n >= size) {
        size = 0;
    } else {
        size -= n;
    }
}

void ListSeq::list_print_reverse() {
    for(int i = size-1; i >= 0; --i) {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}

void ListSeq::list_add(int n, int *vet) {
    if(n > 0 && data) {
        int k = 0, restantes = capacity-size > n ?  n: capacity-size;
        for(int i = size-1; i < restantes; ++i) {
            data[i] = vet[k++];
        }
    }
}

bool ListSeq::list_is_sorted() {
    for (int i = 1; i < size; ++i) {
        if (data[i - 1] > data[i]) return false;
    }
    return true;
}

void ListSeq::list_reverse() {
    if(size == 2) {
        int temp = data[0];
        data[0] = data[1];
        data[1] = temp;
    } else if(size >= 2) {
        int d = 0, e = size-1;
        while(d < e) {
            int temp = data[d];
            data[d] = data[e];
            data[e] = temp;
            ++d;
            --e;
        }
    }
}

bool ListSeq::list_equal(ListSeq *outra) {
    if (!outra || outra->size != size) return false;
    for (int i = 0; i < size; ++i) {
        if (data[i] != outra->data[i]) return false;
    }
    return true;
}

int ListSeq::list_concat(ListSeq *list2) {
    if(list2) {
        if(list2->data) {
            int q = capacity-size >= list2->size ? list2->size : capacity-size;
            for(int i = 0; i < q; ++i) {
                add(list2->get(i));
            }
            return q;
        }
    }
    return -1;
}

ListSeq *list_from_vector(int n, int* vet) {
    if(vet && n > 0) {
        ListSeq *res = new ListSeq(n*2);
        if(res) {
            if(res->data) {
                for(int i = 0; i < n; ++i) {
                    res->add(vet[i]);
                }
                return res;
            }
        }
    }
    return nullptr;
}

ListSeq *list_copy(ListSeq *outra) {
    if(outra) {
        if(outra->data) {
            ListSeq *res = new ListSeq(outra->size);
            if(res) {
                for(int i = 0; i < outra->size; ++i) {
                    res->add(outra->data[i]);
                }
                return res;
            }
        }
    }
    return nullptr;
}