#yanivg1000@gmail.com
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
VALGRIND = valgrind --leak-check=full --track-origins=yes

# Sources
MAIN_SRC = src/main.cpp
TEST_SRC = tests/MyContainer_test.cpp
CONTAINER_HEADER = src/MyContainer.hpp

# Executables
MAIN_EXE = main
TEST_EXE = test

.PHONY: all clean main test valgrind

all: Main test

Main: $(MAIN_SRC) 
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXE) $(MAIN_SRC)

test: $(TEST_SRC) $(CONTAINER_HEADER)
	$(CXX) $(CXXFLAGS) -Isrc -o $(TEST_EXE) $(TEST_SRC)

valgrind: test
	$(VALGRIND) ./$(TEST_EXE)

clean:
	rm -f $(MAIN_EXE) $(TEST_EXE)
