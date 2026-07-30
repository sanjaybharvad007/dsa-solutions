# C++ Solutions

The C++ companion to the Python solutions in this repo. Each solution is
header-only, with approach + intuition + complexity explained in the file.

## Build & test

```bash
cd cpp
g++ -std=c++20 -Wall -Wextra -O2 -I. test_solutions.cpp -o test_solutions
./test_solutions
```

Or with CMake:

```bash
cd cpp
cmake -S . -B build && cmake --build build && cd build && ctest --output-on-failure
```

## Structure

```
cpp/
├── arrays/
│   ├── two_sum.hpp
│   └── max_subarray.hpp
├── linked_lists/reverse_list.hpp
├── trees/level_order.hpp
├── dynamic_programming/climb_stairs.hpp
├── graphs/num_islands.hpp
└── test_solutions.cpp
```
