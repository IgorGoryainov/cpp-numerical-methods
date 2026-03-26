# cpp-numerical-methods

Two classic numerical computing tasks implemented in C++: approximating cosh(x) via a Taylor series, and multiplying matrices.

## What it does

**Task 1 — cosh(x) Taylor series**
Given a value `x` and a precision `epsilon`, computes cosh(x) by accumulating terms of its Taylor series until the current term falls below epsilon. Reports the approximate value, the exact value from `std::cosh`, and both absolute and relative errors.

**Task 2 — Matrix multiplication**
Reads two integer matrices and produces their product. Handles both console input and file input (see `data/`).

## Requirements

- C++17 or later
- CMake 3.16+
- A C++ compiler (GCC, Clang, MSVC)

## Build

```bash
cmake -B build
cmake --build build
```

Run the main program:
```bash
./build/numerical_methods
```

Run tests:
```bash
cd build && ctest --output-on-failure
```

## Input format

**Task 1** reads `x` and `epsilon` from stdin (epsilon must be less than 1):
```
90 0.001
```

**Task 2** reads matrix dimensions `m n k`, then the elements of an m×n matrix followed by an n×k matrix:
```
2 2 2
1 5
7 9
15 17
11 19
```

File inputs follow the same format. Sample files are in `data/`.
