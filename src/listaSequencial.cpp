#include <listaSequencial.hpp>

ListaSequencial::ListaSequencial(int _capacity) {
    data = new int[_capacity];
    if(data) capacity = _capacity;
}

void ListaSequencial::destroy() {
    if(data) {
        delete[] data;
        size = 0;
        capacity = 0;
        data = nullptr;
    }
}

bool ListaSequencial::resize() {
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

bool ListaSequencial::print() {
    if(data) {
        for(int i = 0; i < size; ++i) {
            std::cout << data[i] << ' ';
        }
        std::cout << '\n';
    }
    return true;
}

int ListaSequencial::find(int elem) {
    if(data) for(int i = 0; i < size; ++i) if(data[i] == elem) return i;
    return -1;
}

int ListaSequencial::get(int pos) {
    if(data && pos < size) return data[pos];
    return -1;
}

bool ListaSequencial::isEmpty() {
    return size == 0;
}

bool ListaSequencial::isFull() {
    return size == capacity;
}

bool ListaSequencial::add(int elem) {
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

bool ListaSequencial::remove() {
    --size;
    return true;
}

void ListaSequencial::insert(int elem, int pos) {
    if(data && pos < size && pos >= 0 && (size < capacity || resize())) {
        ++size;
        for(int i = size; i > pos; --i) data[i] = data[i-1];
        data[pos] = elem;
    }
}

void ListaSequencial::removeAt(int pos) {
    if(data && pos >= 0 && pos < size) {
        for(int i = pos; i < size; ++i) {
            data[i] = data[i+1];
        }
        --size;
    }
}

bool ListaSequencial::addSorted(int elem) {
    for(int i = 0; i < size; ++i) {
        if(data[i] < elem) {
            insert(elem, i+1);
            return true;
        }
    }
    return false;
}
