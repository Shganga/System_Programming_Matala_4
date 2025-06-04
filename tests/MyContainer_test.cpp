//yanivg1000@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"  

TEST_CASE("MyContainer basic operations") {
    MyContainer<int> container;

    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    CHECK(container.size() == 5);

    std::ostringstream oss;
    oss << container;
    CHECK(oss.str() == "[7, 15, 6, 1, 2]");

    // בדיקת מחיקת איבר בודד (קיים פעם אחת)
    container.remove(6);
    CHECK(container.size() == 4);

    oss.str("");
    oss.clear();
    oss << container;
    CHECK(oss.str() == "[7, 15, 1, 2]");

    container.add(15);
    container.add(15);
    CHECK(container.size() == 6);

    container.remove(15);
    CHECK(container.size() == 3);

    oss.str("");
    oss.clear();
    oss << container;
    CHECK(oss.str() == "[7, 1, 2]");

    CHECK_THROWS_AS(container.remove(99), std::invalid_argument);

    MyContainer<int> emptyContainer;
    CHECK_THROWS_AS(emptyContainer.remove(1), std::invalid_argument);
}


TEST_CASE("AscendingOrder iterator") {
    MyContainer<int> container;
    for (int i : {7, 15, 6, 1, 2}) container.add(i);

    CHECK(container.size() == 5);

    std::vector<int> expected = {1, 2, 6, 7, 15};
    MyContainer<int>::AscendingOrder asc = container.ascending_order();
    std::vector<int> result(asc.begin(), asc.end());
    CHECK(result == expected);
}

TEST_CASE("DescendingOrder iterator") {
    MyContainer<int> container;
    for (int i : {7, 15, 6, 1, 2}) container.add(i);

    std::vector<int> expected = {15, 7, 6, 2, 1};
    MyContainer<int>::DescendingOrder des = container.descending_order();
    std::vector<int> result(des.begin(), des.end());

    CHECK(result == expected);
}

TEST_CASE("ReverseOrder iterator") {
    MyContainer<int> container;
    for (int i : {7, 15, 6, 1, 2}) container.add(i);

    std::vector<int> expected = {2, 1, 6, 15, 7};
    MyContainer<int>::ReverseOrder rev = container.reverse_order();
    std::vector<int> result(rev.begin(), rev.end());

    CHECK(result == expected);
}

TEST_CASE("SideCrossOrder iterator") {
    MyContainer<int> container;
    for (int i : {7, 15, 6, 1, 2}) container.add(i);

    std::vector<int> expected = {1, 15, 2, 7, 6};
    MyContainer<int>::SideCrossOrder sic = container.side_cross_order();
    std::vector<int> result(sic.begin(), sic.end());

    CHECK(result == expected);
}

TEST_CASE("MiddleOutOrder iterator") {
    MyContainer<int> container;
    for (int i : {7, 15, 6, 1, 2}) container.add(i);

    std::vector<int> expected = {6, 15, 1, 7, 2};
    MyContainer<int>::MiddleOutOrder mio = container.middle_out_order();
    std::vector<int> result(mio.begin(), mio.end());

    CHECK(result == expected);
}

TEST_CASE("Order iterator scans in original order") {
    MyContainer<int> container;
    for (int i : {7, 15, 6, 1, 2}) container.add(i);

    std::vector<int> expected = {7, 15, 6, 1, 2};
    MyContainer<int>::Order order = container.order();
    std::vector<int> result(order.begin(), order.end());

    CHECK(result == expected);
}

TEST_CASE("Iterators on empty container") {
    MyContainer<int> container;

    CHECK(container.ascending_order().begin() == container.ascending_order().end());
    CHECK(container.descending_order().begin() == container.descending_order().end());
    CHECK(container.reverse_order().begin() == container.reverse_order().end());
    CHECK(container.side_cross_order().begin() == container.side_cross_order().end());
    CHECK(container.middle_out_order().begin() == container.middle_out_order().end());
    CHECK(container.order().begin() == container.order().end());
}

