#pragma once
#include <stdexcept>

template<typename T>
class MyContainer;

template<typename T>
class Order {
private:
    const MyContainer<T>& container;
    size_t pos;

public:
    /**
     * @brief Construct an order iterator (natural order, index 0..N-1)
     * @param cont Reference to container
     * @param position Current iterator position (default 0)
     */
    Order(const MyContainer<T>& cont, size_t position = 0)
        : container(cont), pos(position) {}

    /**
     * @brief Dereference to get current element
     * @return const T& Reference to element at position
     */
    const T& operator*() const {
        if (pos >= container.size()) {
            throw std::out_of_range("Iterator out of bounds");
        }
        return container.data[pos];
    }

    /**
     * @brief Pre-increment
     * @return Reference to incremented iterator
     */
    Order& operator++() {
        if (pos >= container.size()) {
            throw std::out_of_range("Cannot increment iterator past end");
        }
        ++pos;
        return *this;
    }

    /**
     * @brief Post-increment
     * @return Iterator before increment
     */
    Order operator++(int) {
        if (pos >= container.size()) {
            throw std::out_of_range("Cannot increment iterator past end");
        }
        Order temp = *this;
        ++pos;
        return temp;
    }

    /**
     * @brief Equality comparison
     */
    bool operator==(const Order& other) const {
        return pos == other.pos && &container == &other.container;
    }

    /**
     * @brief Inequality comparison
     */
    bool operator!=(const Order& other) const {
        return !(*this == other);
    }
};
