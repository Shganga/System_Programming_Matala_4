#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace MyContainerNS;

TEST_CASE("Ascending Iterator Tests") {
    SUBCASE("EmptyContainer") {
        MyContainer<int> container;
        CHECK(container.begin_asc() == container.end_asc());
        CHECK_THROWS_AS(*container.begin_asc(), std::out_of_range);
    }
    SUBCASE("SingleElement") {
        MyContainer<int> container;
        container.add(42);
        auto it = container.begin_asc();
        CHECK(*it == 42);
        ++it;
        CHECK(it == container.end_asc());
    }
    SUBCASE("IntegerElements") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);
        std::vector<int> expected = {1, 2, 6, 7, 15};
        std::vector<int> result;
        for (auto it = container.begin_asc(); it != container.end_asc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
    SUBCASE("StringElements") {
        MyContainer<std::string> container;
        container.add("banana");
        container.add("apple");
        container.add("cherry");
        std::vector<std::string> expected = {"apple", "banana", "cherry"};
        std::vector<std::string> result;
        for (auto it = container.begin_asc(); it != container.end_asc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Descending Iterator Tests") {
    SUBCASE("EmptyContainer") {
        MyContainer<int> container;
        CHECK(container.begin_desc() == container.end_desc());
        CHECK_THROWS_AS(*container.begin_desc(), std::out_of_range);
    }
    SUBCASE("SingleElement") {
        MyContainer<int> container;
        container.add(42);
        auto it = container.begin_desc();
        CHECK(*it == 42);
        ++it;
        CHECK(it == container.end_desc());
    }
    SUBCASE("IntegerElements") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);
        std::vector<int> expected = {15, 7, 6, 2, 1};
        std::vector<int> result;
        for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
    SUBCASE("StringElements") {
        MyContainer<std::string> container;
        container.add("banana");
        container.add("apple");
        container.add("cherry");
        std::vector<std::string> expected = {"cherry", "banana", "apple"};
        std::vector<std::string> result;
        for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("SideCross Iterator Tests") {
    SUBCASE("EmptyContainer") {
        MyContainer<int> container;
        CHECK(container.begin_sidecross() == container.end_sidecross());
        CHECK_THROWS_AS(*container.begin_sidecross(), std::out_of_range);
    }
    SUBCASE("SingleElement") {
        MyContainer<int> container;
        container.add(42);
        auto it = container.begin_sidecross();
        CHECK(*it == 42);
        ++it;
        CHECK(it == container.end_sidecross());
    }
    SUBCASE("IntegerElements") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        container.add(3);
        container.add(4);
        container.add(5);
        // sidecross order: first, last, second, second-last, third...
        std::vector<int> expected = {1, 5, 2, 4, 3};
        std::vector<int> result;
        for (auto it = container.begin_sidecross(); it != container.end_sidecross(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
    SUBCASE("StringElements") {
        MyContainer<std::string> container;
        container.add("a");
        container.add("b");
        container.add("c");
        container.add("d");
        std::vector<std::string> expected = {"a", "d", "b", "c"};
        std::vector<std::string> result;
        for (auto it = container.begin_sidecross(); it != container.end_sidecross(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Reverse Iterator Tests") {
    SUBCASE("EmptyContainer") {
        MyContainer<int> container;
        CHECK(container.begin_reverse() == container.end_reverse());
        CHECK_THROWS_AS(*container.begin_reverse(), std::out_of_range);
    }
    SUBCASE("SingleElement") {
        MyContainer<int> container;
        container.add(42);
        auto it = container.begin_reverse();
        CHECK(*it == 42);
        ++it;
        CHECK(it == container.end_reverse());
    }
    SUBCASE("IntegerElements") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        container.add(3);
        std::vector<int> expected = {3, 2, 1};
        std::vector<int> result;
        for (auto it = container.begin_reverse(); it != container.end_reverse(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
    SUBCASE("StringElements") {
        MyContainer<std::string> container;
        container.add("x");
        container.add("y");
        container.add("z");
        std::vector<std::string> expected = {"z", "y", "x"};
        std::vector<std::string> result;
        for (auto it = container.begin_reverse(); it != container.end_reverse(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Original Order Iterator Tests") {
    SUBCASE("EmptyContainer") {
        MyContainer<int> container;
        CHECK(container.begin_order() == container.end_order());
        CHECK_THROWS_AS(*container.begin_order(), std::out_of_range);
    }
    SUBCASE("SingleElement") {
        MyContainer<int> container;
        container.add(42);
        auto it = container.begin_order();
        CHECK(*it == 42);
        ++it;
        CHECK(it == container.end_order());
    }
    SUBCASE("IntegerElements") {
        MyContainer<int> container;
        container.add(7);
        container.add(15);
        container.add(6);
        container.add(1);
        container.add(2);
        std::vector<int> expected = {7, 15, 6, 1, 2};
        std::vector<int> result;
        for (auto it = container.begin_order(); it != container.end_order(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
    SUBCASE("StringElements") {
        MyContainer<std::string> container;
        container.add("banana");
        container.add("apple");
        container.add("cherry");
        std::vector<std::string> expected = {"banana", "apple", "cherry"};
        std::vector<std::string> result;
        for (auto it = container.begin_order(); it != container.end_order(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("MiddleOut Iterator Tests") {
    SUBCASE("EmptyContainer") {
        MyContainer<int> container;
        CHECK(container.begin_middleout() == container.end_middleout());
        CHECK_THROWS_AS(*container.begin_middleout(), std::out_of_range);
    }
    SUBCASE("SingleElement") {
        MyContainer<int> container;
        container.add(42);
        auto it = container.begin_middleout();
        CHECK(*it == 42);
        ++it;
        CHECK(it == container.end_middleout());
    }
    SUBCASE("IntegerElementsOdd") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        container.add(3);
        container.add(4);
        container.add(5);
        // middle out order for odd count, example: 3 2 4 1 5
        std::vector<int> expected = {3, 2, 4, 1, 5};
        std::vector<int> result;
        for (auto it = container.begin_middleout(); it != container.end_middleout(); ++it) {
            result.push_back(*it);
        }
        
        CHECK(result == expected);
    }
    SUBCASE("IntegerElementsEven") {
        MyContainer<int> container;
        container.add(1);
        container.add(2);
        container.add(3);
        container.add(4);
        // middle out order for even count, example: 2 1 3 4
        
        std::vector<int> expected = {3, 2, 4, 1};
        std::vector<int> result;
        for (auto it = container.begin_middleout(); it != container.end_middleout(); ++it) {
            result.push_back(*it);
            std::cout << *it << ' ';
        }
        CHECK(result == expected);
    }
    SUBCASE("StringElements") {
        MyContainer<std::string> container;
        container.add("a");
        container.add("b");
        container.add("c");
        container.add("d");
        container.add("e");
        std::vector<std::string> expected = {"c", "b", "d", "a", "e"};
        std::vector<std::string> result;
        for (auto it = container.begin_middleout(); it != container.end_middleout(); ++it) {
            result.push_back(*it);
        }
        CHECK(result == expected);
    }
}

TEST_CASE("Equel Test"){
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);
    std::vector<int> asc_result;
    for (auto it = container.begin_asc(); it != container.end_asc(); ++it) {
        asc_result.push_back(*it);
    }
    std::vector<int> dec_result;
    for (auto it = container.begin_desc(); it != container.end_desc(); ++it) {
        dec_result.push_back(*it);
    }
    std::vector<int> side_result;
    for (auto it = container.begin_sidecross(); it != container.end_sidecross(); ++it) {
        side_result.push_back(*it);
    }
    std::vector<int> rev_result;
    for (auto it = container.begin_reverse(); it != container.end_reverse(); ++it) {
        rev_result.push_back(*it);
    }
    std::vector<int> result;
    for (auto it = container.begin_order(); it != container.end_order(); ++it) {
        result.push_back(*it);
    }

    CHECK(result != rev_result);
    CHECK(result != asc_result);
    CHECK(result != dec_result);
    CHECK(asc_result != side_result);
    CHECK(rev_result != side_result);
    CHECK(dec_result != side_result);
}