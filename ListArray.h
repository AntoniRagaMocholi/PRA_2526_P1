#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* data;
    int capacity;
    int count;

    void resize(int new_capacity);

public:
    ListArray();
    ~ListArray();

    void insert(int pos, T e) override;
    void append(T e) override;
    void prepend(T e) override;
    T remove(int pos) override;
    T get(int pos) const override;
    int search(T e) const override;
    bool empty() const override;
    int size() const override;
};

template <typename T>
ListArray<T>::ListArray() {
    capacity = 10;
    count = 0;
    data = new T[capacity];
}

template <typename T>
ListArray<T>::~ListArray() {
    delete[] data;
}

template <typename T>
void ListArray<T>::resize(int new_capacity) {
    T* new_data = new T[new_capacity];
    for (int i = 0; i < count; ++i)
        new_data[i] = data[i];
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

template <typename T>
void ListArray<T>::insert(int pos, T e) {
    if (pos < 0 || pos > count)
        throw std::out_of_range("Posición inválida");

    if (count == capacity)
        resize(capacity * 2);

    for (int i = count; i > pos; --i)
        data[i] = data[i - 1];

    data[pos] = e;
    ++count;
}

template <typename T>
void ListArray<T>::append(T e) {
    insert(count, e);
}

template <typename T>
void ListArray<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
T ListArray<T>::remove(int pos) {
    if (pos < 0 || pos >= count)
        throw std::out_of_range("Posición inválida");

    T removed = data[pos];
    for (int i = pos; i < count - 1; ++i)
        data[i] = data[i + 1];
    --count;
    return removed;
}

template <typename T>
T ListArray<T>::get(int pos) const {
    if (pos < 0 || pos >= count)
        throw std::out_of_range("Posición inválida");
    return data[pos];
}

template <typename T>
int ListArray<T>::search(T e) const {
    for (int i = 0; i < count; ++i)
        if (data[i] == e)
            return i;
    return -1;
}

template <typename T>
bool ListArray<T>::empty() const {
    return count == 0;
}

template <typename T>
int ListArray<T>::size() const {
    return count;
}

#endif
