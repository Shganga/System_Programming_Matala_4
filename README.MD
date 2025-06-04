# MyContainer
mail : [yanivg1000@gmail.com](yanivg1000@gmail.com)

`MyContainer` is a generic container class in C++ that allows storing, adding, and removing elements of any type.

---

## Features

- Add a new element (`add`)
- Remove all occurrences of an existing element (`remove`)
- Get the container size (`size`)
- Output operator for easy printing
- Throws exceptions when trying to remove a non-existing element
- Iterators for various traversal orders (Ascending, Descending, MiddleOut, SideCross, etc.)

---

## Requirements

- C++11 or later compiler (g++ or clang)
- Standard STL libraries (vector, sort, etc.)

---

## Tests

Tests are located in `tests/MyContainer_test.cpp` and cover:

- Adding and removing elements correctly  
- Correct container size reporting  
- Output operator functionality  
- Exception throwing on invalid removal  
- Iterator behavior for various traversal orders  

---

## Build and Run

To compile and run the main

```bash
    make Main
```

To compile and run the tests

```bash
    make test
```

To compile and run valgrind

```bash
    make valgrind
```

To clean

```bash
    make clean
```

---