#include <iostream>
#include "ListLinked.h"

int main() {
    ListLinked<int> l;

    std::cout << "List => " << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;

    l.append(0);
    l.append(5);
    l.append(10);
    l.prepend(-5);

    std::cout << "\nList => " << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;

    std::cout << "\nl.get(0) => " << l.get(0) << "; l[0] => " << l[0] << std::endl;
    std::cout << "l.get(3) => " << l.get(3) << "; l[3] => " << l[3] << std::endl;

    std::cout << "\nl.remove(3) => " << l.remove(3) << ": " << std::endl;
    std::cout << "l.remove(1) => " << l.remove(1) << ": " << std::endl;
    std::cout << "l.remove(0) => " << l.remove(0) << ": " << std::endl;

    std::cout << "\nList => " << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;

    l.prepend(33);
    l.append(14);

    std::cout << "\nList => " << l << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "empty(): " << std::boolalpha << l.empty() << std::endl;

    std::cout << "\nl.search(14) => " << l.search(14) << std::endl;
    std::cout << "l.search(55) => " << l.search(55) << std::endl;

    try {
        std::cout << "l.insert(-1, 99) => ";
        l.insert(-1, 99);
    } catch (const std::out_of_range& e) {
        std::cout << "std::out_of_range: " << e.what() << std::endl;
    }

    try {
        std::cout << "l.insert(4, 99) => ";
        l.insert(4, 99);
    } catch (const std::out_of_range& e) {
        std::cout << "std::out_of_range: " << e.what() << std::endl;
    }

    try {
        std::cout << "l.get(-1) => ";
        std::cout << l.get(-1) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "std::out_of_range: " << e.what() << std::endl;
    }

    try {
        std::cout << "l.get(3) => ";
        std::cout << l.get(3) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "std::out_of_range: " << e.what() << std::endl;
    }

    try {
        std::cout << "l.remove(-1) => ";
        std::cout << l.remove(-1) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "std::out_of_range: " << e.what() << std::endl;
    }

    try {
        std::cout << "l.remove(3) => ";
        std::cout << l.remove(3) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "std::out_of_range: " << e.what() << std::endl;
    }

    return 0;
}

