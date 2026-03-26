cmake_minimum_required(VERSION 3.16)
project(NumericalMethods VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library: series and matrix logic (no main)
add_library(num_methods_lib
    src/series.cpp
    src/series_io.cpp
    src/matrix.cpp
    src/matrix_io.cpp
)
target_include_directories(num_methods_lib PUBLIC src)

# Main executable
add_executable(numerical_methods src/main.cpp)
target_link_libraries(numerical_methods PRIVATE num_methods_lib)

# Tests
enable_testing()

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.6.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(tests
    tests/test_series.cpp
    tests/test_matrix.cpp
)
target_link_libraries(tests PRIVATE num_methods_lib Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE src)

include(CTest)
include(Catch)
catch_discover_tests(tests)
