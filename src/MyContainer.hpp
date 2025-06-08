#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

// Include iterator headers
#include "AscendingOrder.hpp"
#include "DescendingOrder.hpp"
#include "SideCrossOrder.hpp"
#include "ReverseOrder.hpp"
#include "MiddleOutOrder.hpp"
#include "Order.hpp"

template<typename T = int>
class MyContainer {
private:
    std::vector<T> data;  ///< Underlying data storage

public:

    /**
     * @brief Default constructor
     */
    MyContainer() = default;

    /**
     * @brief Default destructor
     */
    ~MyContainer() = default;

    /**
     * @brief Add an item to the container
     * @param item The item to add
     */
    void add(const T& item) {
        data.push_back(item);
    }

    /**
     * @brief Remove all instances of an item from the container
     * @param item The item to remove
     * @throws std::invalid_argument if item is not found
     */
    void remove(const T& item) {
        auto it = std::remove(data.begin(), data.end(), item);
        if (it == data.end()) {
            throw std::invalid_argument("Item not found in container");
        }
        data.erase(it, data.end());
    }

    /**
     * @brief Get the number of elements in the container
     * @return The container size
     */
    size_t size() const {
        return data.size();
    }

    /**
     * @brief Output container elements as a list
     * @param os Output stream
     * @param container Container to output
     * @return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
        os << "[";
        for (size_t i = 0; i < container.data.size(); ++i) {
            os << container.data[i];
            if (i != container.data.size() - 1) os << ", ";
        }
        os << "]";
        return os;
    }


    friend class AscendingOrder<T>;
    friend class DescendingOrder<T>;
    friend class SideCrossOrder<T>;
    friend class ReverseOrder<T>;
    friend class MiddleOutOrder<T>;
    friend class Order<T>;

    /**
     * @brief Get iterator to the beginning in ascending order
     * @return AscendingOrderIterator pointing to first element
     */
    auto begin_asc() const {
        return AscendingOrder<T>(*this, 0);
    }

    /**
     * @brief Get iterator to the end in ascending order
     * @return AscendingOrderIterator pointing past last element
     */
    auto end_asc() const {
        return AscendingOrder<T>(*this, data.size());
    }

    /**
     * @brief Get iterator to the beginning in descending order
     * @return DescendingOrderIterator pointing to first element
     */
    auto begin_desc() const {
        return DescendingOrder<T>(*this, 0);
    }

    /**
     * @brief Get iterator to the end in descending order
     * @return DescendingOrderIterator pointing past last element
     */
    auto end_desc() const {
        return DescendingOrder<T>(*this, data.size());
    }

    /**
     * @brief Get iterator to the beginning in side-cross order
     * @return SideCrossOrderIterator pointing to first element
     */
    auto begin_sidecross() const {
        return SideCrossOrder<T>(*this, 0);
    }

    /**
     * @brief Get iterator to the end in side-cross order
     * @return SideCrossOrderIterator pointing past last element
     */
    auto end_sidecross() const {
        return SideCrossOrder<T>(*this, data.size());
    }

    /**
     * @brief Get iterator to the beginning in reverse order
     * @return ReverseOrderIterator pointing to first element
     */
    auto begin_reverse() const {
        return ReverseOrder<T>(*this, 0);
    }

    /**
     * @brief Get iterator to the end in reverse order
     * @return ReverseOrderIterator pointing past last element
     */
    auto end_reverse() const {
        return ReverseOrder<T>(*this, data.size());
    }

    /**
     * @brief Get iterator to the beginning in middle-out order
     * @return MiddleOutOrderIterator pointing to first element
     */
    auto begin_middleout() const {
        return MiddleOutOrder<T>(*this, 0);
    }

    /**
     * @brief Get iterator to the end in middle-out order
     * @return MiddleOutOrderIterator pointing past last element
     */
    auto end_middleout() const {
        return MiddleOutOrder<T>(*this, data.size());
    }

    /**
     * @brief Get iterator to the beginning in insertion order
     * @return OrderIterator pointing to first element
     */
    auto begin_order() const {
        return Order<T>(*this, 0);
    }

    /**
     * @brief Get iterator to the end in insertion order
     * @return OrderIterator pointing past last element
     */
    auto end_order() const {
        return Order<T>(*this, data.size());
    }


};
