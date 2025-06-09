#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace MyContainerNS{


template<typename T>
class MyContainer;

template<typename T>
class ReverseOrder {
private:
    const MyContainer<T>& container;
    size_t pos;

public:
    /**
     * @brief Construct a ReverseOrder iterator
     * @param container Reference to the container to iterate over
     * @param position Iterator position (default 0)
     */
    ReverseOrder(const MyContainer<T>& con, size_t position = 0)
        : container(con) {
            pos = con.size() == 0 ? 0 : con.size() - 1 - position;
        }

    /**
     * @brief Dereference operator
     * @return Reference to current element
     * @throw std::out_of_range If out of bounds
     */
    const T& operator*() const {
         if (pos == static_cast<size_t>(-1) || pos >= container.size()) {
            throw std::out_of_range("Iterator out of bounds");
        }
        //return reversedData[pos];
        return container.data[pos];
    }

    /**
     * @brief Prefix ++: moves iterator one step in reverse.
     * @throws std::out_of_range if already at end.
     */

    /**
     * @brief Postfix ++: moves iterator one step in reverse, returns previous state.
     * @throws std::out_of_range if already at end.
     */
    ReverseOrder& operator++() {
        if (pos == static_cast<size_t>(-1)) {
            throw std::out_of_range("Cannot increment iterator past end");
        }
        if (pos == 0) {
            pos = static_cast<size_t>(-1);
        } else {
            --pos;
        }
        return *this;
    }

    ReverseOrder operator++(int) {
        if (pos == static_cast<size_t>(-1)) {
            throw std::out_of_range("Cannot increment iterator past end");
        }
        ReverseOrder temp = *this;
        if (pos == 0) {
            pos = static_cast<size_t>(-1);
        } else {
            --pos;
        }
        return temp;
    }

    /**
     * @brief Equality comparison operator
     */
    bool operator==(const ReverseOrder& other) const {
        return pos == other.pos && &container == &other.container;
        // Note: We compare pointer addresses of internal vector data,
        // because reversedData is a copied vector, so container address won't match.
    }

    /**
     * @brief Inequality comparison operator
     */
    bool operator!=(const ReverseOrder& other) const {
        return !(*this == other);
    }
};
}
