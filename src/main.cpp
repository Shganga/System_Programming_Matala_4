#include "MyContainer.hpp"
#include <iostream>
#include <string>

int main() {
    MyContainer<> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);


    std::cout << "Size of container: " << container.size() << std::endl;

    std::cout << "Original Order: ";
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Ascending Order: ";
    for (auto it = container.begin_asc(); it != container.end_asc(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Descending Order: ";
    for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Side Cross Order: ";
    for (auto it = container.begin_sidecross(); it != container.end_sidecross(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Reverse Order: ";
    for (auto it = container.begin_reverse(); it != container.end_reverse(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Middle Out Order: ";
    for (auto it = container.begin_middleout(); it != container.end_middleout(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "\n--- String Container ---" << std::endl;

    MyContainer<std::string> strContainer;
    strContainer.add("apple");
    strContainer.add("banana");
    strContainer.add("cherry");
    strContainer.add("date");
    strContainer.add("elderberry");

    std::cout << "Original Order: ";
    for (auto it = strContainer.begin_order(); it != strContainer.end_order(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Ascending Order: ";
    for (auto it = strContainer.begin_asc(); it != strContainer.end_asc(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Descending Order: ";
    for (auto it = strContainer.begin_desc(); it != strContainer.end_desc(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Side Cross Order: ";
    for (auto it = strContainer.begin_sidecross(); it != strContainer.end_sidecross(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Reverse Order: ";
    for (auto it = strContainer.begin_reverse(); it != strContainer.end_reverse(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "Middle Out Order: ";
    for (auto it = strContainer.begin_middleout(); it != strContainer.end_middleout(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    return 0;
}
