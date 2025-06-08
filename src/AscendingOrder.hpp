#pragma once
#include <stdexcept>
#include <numeric>

template<typename T>
class MyContainer;


template<typename T>
class AscendingOrder {
private:
    const MyContainer<T>& container;
    std::vector<size_t> indices;
    size_t pos;

public:
    /**
     * @brief Construct an ascending order iterator
     * 
     * @param cont Reference to the container to iterate over
     * @param position Position index in the sorted order (default 0 - begin)
     */
    AscendingOrder(const MyContainer<T>& cont, size_t position = 0)
        : container(cont), pos(position) {
        indices.resize(container.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(), [&](size_t a, size_t b) {
            return container.data[a] < container.data[b];
        });
    }

    /**
     * @brief Dereference iterator to get element
     * 
     * @return const T& Reference to current element
     */
    const T& operator*() const {
        if (pos >= container.size()) {
            throw std::out_of_range("Iterator out of bounds");
        }
        return container.data[indices[pos]];
    }

    /**
     * @brief Pre-increment iterator
     * 
     * @return AscendingOrder& Reference to incremented iterator
     */
    AscendingOrder& operator++() {
        if (pos >= container.size()) {
            throw std::out_of_range("Cannot increment iterator past end");
        }
        ++pos;
        return *this;
    }

    /**
     * @brief Post-increment iterator
     * 
     * @return AscendingOrder Iterator before increment
     */
    AscendingOrder operator++(int) {
        if (pos >= container.size()) {
            throw std::out_of_range("Cannot increment iterator past end");
        }
        AscendingOrder temp = *this;
        ++pos;
        return temp;
    }

    /**
     * @brief Equality comparison
     */
    bool operator==(const AscendingOrder& other) const {
        return pos == other.pos && &container == &other.container;
    }

    /**
     * @brief Inequality comparison
     */
    bool operator!=(const AscendingOrder& other) const {
        return !(*this == other);
    }
};
