#include "int_list_t.h"

int_list_t::int_list_t(): tail(new node_t {0, nullptr, nullptr}), _size(0) {
    tail->prev = tail;
    tail->next = tail;
}

int_list_t::int_list_t(const int_list_t & other): int_list_t() {
    *this = other;
}

int_list_t::int_list_t(size_t count, int value): int_list_t() {
    for (size_t i = 0; i < count; ++i) {
        push_back(value);
    }
}

int_list_t::~int_list_t() {
    clear();

    delete tail;
}

int_list_t & int_list_t::operator=(const int_list_t & other) {
    if (&other != this) {
        clear();

        for (node_t * node = other.tail->next; node != other.tail; node = node->next) {
            push_back(node->value);
        }
    }

    return *this;
}

int & int_list_t::operator[](size_t pos) {
    return get_node(pos)->value;
}

int int_list_t::operator[](size_t pos) const {
    return get_node(pos)->value;
}

int & int_list_t::back() {
    return tail->prev->value;
}

int int_list_t::back() const {
    return tail->prev->value;
}

int & int_list_t::front() {
    return tail->next->value;
}

int int_list_t::front() const {
    return tail->next->value;
}

void int_list_t::clear() {
    while (!empty()) {
        pop_back();
    }
}

size_t int_list_t::size() const {
    return _size;
}

bool int_list_t::empty() const {
    return _size == 0;
}

void int_list_t::insert(size_t pos, int new_val) {
    node_t * node = get_node(pos);

    auto * new_node = new node_t {new_val, node->prev, node};
    node->prev->next = new_node;
    node->prev = new_node;
    ++_size;
}

void int_list_t::push_front(int new_val) {
    insert(0, new_val);
}

void int_list_t::push_back(int new_val) {
    insert(_size, new_val);
}

void int_list_t::erase(size_t pos) {
    node_t * node = get_node(pos);

    node->next->prev = node->prev;
    node->prev->next = node->next;
    delete node;
    --_size;
}

void int_list_t::pop_front() {
    erase(0);
}

void int_list_t::pop_back() {
    erase(_size - 1);
}

int_list_t int_list_t::splice(size_t start_pos, size_t count) {
    int_list_t new_list;

    node_t * fst = get_node(start_pos);
    node_t * lst = get_node(start_pos + count - 1);
    fst->prev->next = lst->next;
    lst->next->prev = fst->prev;
    fst->prev = new_list.tail;
    lst->next = new_list.tail;
    new_list.tail->next = fst;
    new_list.tail->prev = lst;
    new_list._size = count;

    _size -= count;
    return new_list;
}

int_list_t & int_list_t::merge(int_list_t & other) {
    other.tail->next->prev = tail->prev;
    tail->prev->next = other.tail->next;
    other.tail->prev->next = tail;
    tail->prev = other.tail->prev;
    other.tail->next = other.tail;
    other.tail->prev = other.tail;
    _size += other._size;
    other._size = 0;
    return *this;
}

void int_list_t::reverse() {
    for (node_t * node = tail->next; node != tail; node = node->next) {
        std::swap(node->prev->prev, node->prev->next);
    }

    std::swap(tail->next->prev, tail->next->next);
}

void int_list_t::swap(int_list_t & other) {
    std::swap(tail, other.tail);
    std::swap(_size, other._size);
}

std::istream & operator>>(std::istream & stream, int_list_t & list) {
    int val;

    list.clear();
    while (stream >> val) {
        list.push_back(val);
    }

    return stream;
}

std::ostream & operator<<(std::ostream & stream, const int_list_t & list) {
    for (int_list_t::node_t * node = list.tail->next; node != list.tail->prev; node = node->next) {
        std::cout << node->value << ' ';
    }

    if (!list.empty()) {
        std::cout << list.tail->prev->value;
    }

    return stream;
}

int_list_t::node_t * int_list_t::get_node(size_t pos) const {
    node_t * node = tail;

    if (pos < _size / 2) {
        for (size_t i = 0; i <= pos; ++i) {
            node = node->next;
        }
    } else {
        for (size_t i = pos; i < _size; ++i) {
            node = node->prev;
        }
    }

    return node;
}
