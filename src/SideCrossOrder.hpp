#pragma once
#include <vector>
#include <stdexcept>
#include <numeric>
#include <algorithm>

namespace MyContainerNS{

template<typename T>
class MyContainer;

template<typename T>
class SideCrossOrder {
private:
    const MyContainer<T>& container;
    std::vector<size_t> indices; // indices in side-cross order
    size_t pos;

    void buildIndices() {
         size_t n = container.size();
        indices.clear();
        if (n == 0) return; // חשוב למנוע גישה ל-temp כש-0

        std::vector<size_t> temp(n);
        std::iota(temp.begin(), temp.end(), 0);

        // Sort indices by value
        std::sort(temp.begin(), temp.end(), [&](size_t a, size_t b) {
            return container.data[a] < container.data[b];
        });

        size_t left = 0;
        size_t right = n - 1;

        while (left <= right) {
            if (left == right) {
                indices.push_back(temp[left]);
            } else {
                indices.push_back(temp[left]);
                indices.push_back(temp[right]);
            }
            ++left;
            if (right > 0) --right; // avoid underflow
        }
    }

public:
    /**
     * @brief Construct side-cross order iterator
     * @param cont Reference to container
     * @param position Iterator position (default 0)
     */
    SideCrossOrder(const MyContainer<T>& cont, size_t position = 0)
        : container(cont), pos(position) {
        buildIndices();
    }

    /**
     * @brief Dereference operator
     * @return Reference to current element
     * @throw std::out_of_range If out of bounds
     */
    const T& operator*() const {
        if (pos >= container.size()) {
            throw std::out_of_range("Iterator out of bounds");
        }
        return container.data[indices[pos]];
    }

    /**
     * @brief Pre-increment operator
     * @return Reference to incremented iterator
     * @throw std::out_of_range If incrementing past the end
     */
    SideCrossOrder& operator++() {
        if (pos >= container.size()) {
            throw std::out_of_range("Cannot increment iterator past end");
        }
        ++pos;
        return *this;
    }

    /**
     * @brief Post-increment operator
     * @return Iterator before increment
     * @throw std::out_of_range If incrementing past the end
     */
    SideCrossOrder operator++(int) {
        if (pos >= container.size()) {
            throw std::out_of_range("Cannot increment iterator past end");
        }
        SideCrossOrder temp = *this;
        ++pos;
        return temp;
    }

    /**
     * @brief Equality comparison
     */
    bool operator==(const SideCrossOrder& other) const {
        return pos == other.pos && &container == &other.container;
    }

    /**
     * @brief Inequality comparison
     */
    bool operator!=(const SideCrossOrder& other) const {
        return !(*this == other);
    }
};
}
