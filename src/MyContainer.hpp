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

    public:
        using iterator = typename std::vector<T>::const_iterator;

        AscendingOrder(const MyContainer<T>& container) {
            sortedData = container.data;
            std::sort(sortedData.begin(), sortedData.end());
        }

        iterator begin() const { return sortedData.begin(); }
        iterator end() const { return sortedData.end(); }
    };

    class DescendingOrder {
    private:
        std::vector<T> sortedData;

    public:
        using iterator = typename std::vector<T>::const_iterator;

        DescendingOrder(const MyContainer<T>& container) {
            sortedData = container.data;
            std::sort(sortedData.begin(), sortedData.end(), std::greater<T>());
        }

        iterator begin() const { return sortedData.begin(); }
        iterator end() const { return sortedData.end(); }
    };



    class SideCrossOrder {
    private:
        std::vector<T> ordered;

    public:
        using iterator = typename std::vector<T>::const_iterator;

        SideCrossOrder(const MyContainer<T>& container) {
            std::vector<T> sorted = container.data;
            std::sort(sorted.begin(), sorted.end());

            size_t left = 0;
            size_t right = sorted.size() - 1;

            while (left <= right) {
                if (left == right) {
                    ordered.push_back(sorted[left]);
                } else {
                    ordered.push_back(sorted[left]);
                    ordered.push_back(sorted[right]);
                }
                ++left;
                if (right > 0) --right;
            }
        }

        iterator begin() const { return ordered.begin(); }
        iterator end() const { return ordered.end(); }
    };

    class ReverseOrder {
    private:
        std::vector<T> reversedData;

    public:
        using iterator = typename std::vector<T>::const_iterator;

        ReverseOrder(const MyContainer<T>& container) {
            reversedData = container.data;
            std::reverse(reversedData.begin(), reversedData.end());
        }

        iterator begin() const { return reversedData.begin(); }
        iterator end() const { return reversedData.end(); }
    };


    class MiddleOutOrder {
        private:
            std::vector<T> ordered;
        
        public:
            using iterator = typename std::vector<T>::const_iterator;
        
            MiddleOutOrder(const MyContainer<T>& container) {
                const std::vector<T>& data = container.data;
                size_t n = data.size();
                if (n == 0) return;
        
                // בוחרים אינדקס אמצעי (כאן עיגול כלפי מטה)
                size_t mid = n / 2;
        
                ordered.push_back(data[mid]);
        
                // מצביעים שמאלה וימינה מהאמצע
                int left = static_cast<int>(mid) - 1;
                int right = static_cast<int>(mid) + 1;
        
                // לסרוק לסירוגין משמאל ומימין כל עוד יש איברים
                while (left >= 0 || right < (int)n) {
                    if (left >= 0) {
                        ordered.push_back(data[left]);
                        --left;
                    }
                    if (right < (int)n) {
                        ordered.push_back(data[right]);
                        ++right;
                    }
                }
            }
        
            iterator begin() const { return ordered.begin(); }
            iterator end() const { return ordered.end(); }
    };
        
    AscendingOrder ascending_order() const { return AscendingOrder(*this); }
    DescendingOrder descending_order() const { return DescendingOrder(*this); }
    SideCrossOrder side_cross_order() const { return SideCrossOrder(*this); }
    ReverseOrder reverse_order() const { return ReverseOrder(*this); }
    MiddleOutOrder middle_out_order() const { return MiddleOutOrder(*this); }
};
