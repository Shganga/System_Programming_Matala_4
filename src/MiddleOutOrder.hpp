#pragma once
#include <stdexcept>
#include <numeric>

template<typename T>
class MyContainer;


template<typename T>
class MiddleOutOrder {
private:
    const MyContainer<T>& container;
    std::vector<size_t> indices;
    size_t pos;

public:
    /**
     * @brief Construct a middle-out order iterator
     * 
     * @param cont Reference to the container to iterate over
     * @param position Position index in the middle-out order (default 0 - begin)
     */
    MiddleOutOrder(const MyContainer<T>& cont, size_t position = 0)
        : container(cont), pos(position) {
        size_t n = container.size();
        if (n == 0) return;

        size_t mid = n / 2;
        indices.push_back(mid);

        int left = static_cast<int>(mid) - 1;
        int right = static_cast<int>(mid) + 1;

        while (left >= 0 || right < static_cast<int>(n)) {
            if (left >= 0) indices.push_back(left--);
            if (right < static_cast<int>(n)) indices.push_back(right++);
        }
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
     * @return MiddleOutOrder& Reference to incremented iterator
     */
    MiddleOutOrder& operator++() {
        if (pos >= container.size()) {
            throw std::out_of_range("Cannot increment iterator past end");
        }
        ++pos;
        return *this;
    }

    /**
     * @brief Post-increment iterator
     * 
     * @return MiddleOutOrder Iterator before increment
     */
    MiddleOutOrder operator++(int) {
        if (pos >= container.size()) {
            throw std::out_of_range("Cannot increment iterator past end");
        }
        MiddleOutOrder temp = *this;
        ++pos;
        return temp;
    }

    /**
     * @brief Equality comparison
     */
    bool operator==(const MiddleOutOrder& other) const {
        return pos == other.pos && &container == &other.container;
    }

    /**
     * @brief Inequality comparison
     */
    bool operator!=(const MiddleOutOrder& other) const {
        return !(*this == other);
    }
};
