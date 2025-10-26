#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked();
    ~ListLinked();

    void insert(int pos, T e) override;
    void append(T e) override;
    void prepend(T e) override;
    T remove(int pos) override;
    T get(int pos) const override;
    int search(T e) const override;
    bool empty() const override;
    int size() const override;

    T operator[](int pos);
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        out << "[";
        Node<T>* aux = list.first;
        while (aux != nullptr) {
            out << aux->data;
            if (aux->next != nullptr) out << ", ";
            aux = aux->next;
        }
        out << "]";
        return out;
    }
};

// Implementación

template <typename T>
ListLinked<T>::ListLinked() {
    first = nullptr;
    n = 0;
}

template <typename T>
ListLinked<T>::~ListLinked() {
    while (first != nullptr) {
        Node<T>* aux = first->next;
        delete first;
        first = aux;
    }
}

template <typename T>
void ListLinked<T>::insert(int pos, T e) {
    if (pos < 0 || pos > n)
        throw std::out_of_range("Posición inválida");

    if (pos == 0) {
        first = new Node<T>(e, first);
    } else {
        Node<T>* prev = first;
        for (int i = 0; i < pos - 1; ++i)
            prev = prev->next;
        prev->next = new Node<T>(e, prev->next);
    }
    ++n;
}

template <typename T>
void ListLinked<T>::append(T e) {
    insert(n, e);
}

template <typename T>
void ListLinked<T>::prepend(T e) {
    insert(0, e);
}

template <typename T>
T ListLinked<T>::remove(int pos) {
    if (pos < 0 || pos >= n)
        throw std::out_of_range("Posición inválida");

    Node<T>* target;
    T value;

    if (pos == 0) {
        target = first;
        first = first->next;
    } else {
        Node<T>* prev = first;
        for (int i = 0; i < pos - 1; ++i)
            prev = prev->next;
        target = prev->next;
        prev->next = target->next;
    }

    value = target->data;
    delete target;
    --n;
    return value;
}

template <typename T>
T ListLinked<T>::get(int pos) const {
    if (pos < 0 || pos >= n)
        throw std::out_of_range("Posición inválida");

    Node<T>* aux = first;
    for (int i = 0; i < pos; ++i)
        aux = aux->next;
    return aux->data;
}

template <typename T>
int ListLinked<T>::search(T e) const {
    Node<T>* aux = first;
    int index = 0;
    while (aux != nullptr) {
        if (aux->data == e)
            return index;
        aux = aux->next;
        ++index;
    }
    return -1;
}

template <typename T>
bool ListLinked<T>::empty() const {
    return n == 0;
}

template <typename T>
int ListLinked<T>::size() const {
    return n;
}

template <typename T>
T ListLinked<T>::operator[](int pos) {
    return get(pos);
}

#endif

