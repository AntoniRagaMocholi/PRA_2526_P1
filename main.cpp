#include <iostream>
#include "ListArray.h"

int main() {
    ListArray<int> lista;
    lista.append(10);
    lista.append(20);
    lista.prepend(5);
    std::cout << "Elemento en posición 1: " << lista.get(1) << std::endl;
    std::cout << "Tamaño: " << lista.size() << std::endl;
    return 0;
}

