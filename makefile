# yanivg1000@gmail.com
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
VALGRIND = valgrind --leak-check=full --track-origins=yes

SRC_DIR = src
TEST_DIR = tests

MAIN_SRC = $(SRC_DIR)/main.cpp
TEST_SRC = $(TEST_DIR)/MyContainer_test.cpp
HEADERS = $(SRC_DIR)/MyContainer.hpp $(SRC_DIR)/AscendingOrder.hpp $(SRC_DIR)/DescendingOrder.hpp $(SRC_DIR)/SideCrossOrder.hpp $(SRC_DIR)/ReverseOrder.hpp $(SRC_DIR)/Order.hpp $(SRC_DIR)/MiddleOutOrder.hpp

MAIN_EXE = main
TEST_EXE = test

.PHONY: all clean main test valgrind

all: main test

Main: $(MAIN_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -Isrc -o $(MAIN_EXE) $(MAIN_SRC)

test: $(TEST_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -Isrc -o $(TEST_EXE) $(TEST_SRC)

valgrind: test
	$(VALGRIND) ./$(TEST_EXE)

clean:
	rm -f $(MAIN_EXE) $(TEST_EXE)
