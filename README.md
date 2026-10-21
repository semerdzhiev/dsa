# Data Structures and Algorithms

Sample code I use in my courses on Data Structure and Algorithms.

## Build

Requires CMake 3.24+.

To build tests, Catch2 v3 is needed.
The template first tries to locate a locally installed copy
and then falls back to fetching it from the GitHub repo.

```sh
# Build all
cmake -S . -B .build
cmake --build .build

# Build just one module's tests
cmake --build .build --target dsa_utils_tests

# Run all tests
ctest --test-dir .build --output-on-failure

# Run tests with a given label
ctest --test-dir .build -L utils --output-on-failure
```
