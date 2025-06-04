#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

template<typename T = int> 

class MyContainer {
private:
    std::vector<T> data;

public:
    void add(const T& item) {
        data.push_back(item);
    }

    void remove(const T& item) {
        auto it = std::remove(data.begin(), data.end(), item);
        if (it == data.end()) {
            throw std::invalid_argument("Item not found in container");
        }
        data.erase(it, data.end());
    }

    size_t size() const {
        return data.size();
    }

    friend std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
        os << "[";
        for (size_t i = 0; i < container.data.size(); ++i) {
            os << container.data[i];
            if (i != container.data.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

class AscendingOrder {
    private:
        std::vector<T> sortedData;
        typename std::vector<T>::iterator it;

    public:
        AscendingOrder(const MyContainer& container) {
            sortedData = container.data;
            std::sort(sortedData.begin(), sortedData.end());
            it = sortedData.begin();
        }

        typename std::vector<T>::iterator begin() {
            return sortedData.begin();
        }

        typename std::vector<T>::iterator end() {
            return sortedData.end();
        }
};

class DescendingOrder {
    private:
        std::vector<T> sortedData;

    public:
        DescendingOrder(const MyContainer<T>& container) : sortedData(container.data) {
            std::sort(sortedData.begin(), sortedData.end(), std::greater<T>());
        }

        typename std::vector<T>::const_iterator begin() const {
            return sortedData.begin();
        }

        typename std::vector<T>::const_iterator end() const {
            return sortedData.end();
        }
};

class SideCrossOrder {
    private:
        std::vector<T> ordered;
    
    public:
        SideCrossOrder(const MyContainer<T>& container) {
            std::vector<T> sorted = container.data;
            std::sort(sorted.begin(), sorted.end());
    
            size_t left = 0;
            size_t right = sorted.size() - 1;
    
            while (left <= right) {
                if (left == right) {
                    ordered.push_back(sorted[left]);
                    break;
                }
                ordered.push_back(sorted[left]);
                ordered.push_back(sorted[right]);
                ++left;
                --right;
            }
        }
    
        typename std::vector<T>::const_iterator begin() const {
            return ordered.begin();
        }
    
        typename std::vector<T>::const_iterator end() const {
            return ordered.end();
        }
    };

class ReverseOrder {
    private:
        std::vector<T> reversedData;
    
    public:
        ReverseOrder(const MyContainer<T>& container) : reversedData(container.data) {
            std::reverse(reversedData.begin(), reversedData.end());
        }
    
        typename std::vector<T>::const_iterator begin() const {
            return reversedData.begin();
        }
    
        typename std::vector<T>::const_iterator end() const {
            return reversedData.end();
        }
    };
        
    
};




