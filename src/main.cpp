//yanivg1000@gmail.com
#include "MyContainer.hpp"
#include <iostream>

int main() {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    std::cout << "Size of container: " << container.size() << std::endl;

    std::cout << "Order: ";
    for (const auto& x : container.order()) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    std::cout << "Ascending: ";
    for (const auto& x : container.ascending_order()) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    std::cout << "Descending: ";
    for (const auto& x : container.descending_order()) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    std::cout << "Side Cross: ";
    for (const auto& x : container.side_cross_order()) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    std::cout << "Reverse: ";
    for (const auto& x : container.reverse_order()) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    std::cout << "Middle Out: ";
    for (const auto& x : container.middle_out_order()) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    return 0;
}
