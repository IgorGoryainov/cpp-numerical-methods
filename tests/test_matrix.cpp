#include <catch2/catch_test_macros.hpp>
#include "matrix.h"

// Helper to allocate, fill, and free a raw 2D int matrix.
static int** make_matrix(int rows, int cols, std::initializer_list<int> values)
{
    int** m = new int*[rows];
    for (int i = 0; i < rows; i++)
        m[i] = new int[cols];

    auto it = values.begin();
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m[i][j] = (it != values.end()) ? *it++ : 0;

    return m;
}

static void free_matrix(int** m, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] m[i];
    delete[] m;
}

TEST_CASE("check_matrix_input rejects bad dimensions", "[matrix]")
{
    CHECK(check_matrix_input(1, 1, 1) == 0);
    CHECK(check_matrix_input(0, 1, 1) == 1);
    CHECK(check_matrix_input(1, 0, 1) == 1);
    CHECK(check_matrix_input(1, 1, 0) == 1);
    CHECK(check_matrix_input(-1, 2, 3) == 1);
}

TEST_CASE("multiply_matrices: 2x2 * 2x2", "[matrix]")
{
    // [1 5] * [15 17] = [1*15+5*11  1*17+5*19] = [70  112]
    // [7 9]   [11 19]   [7*15+9*11  7*17+9*19]   [204 290]
    int** a = make_matrix(2, 2, {1, 5, 7, 9});
    int** b = make_matrix(2, 2, {15, 17, 11, 19});

    int** r = multiply_matrices(2, 2, 2, a, b);

    CHECK(r[0][0] == 70);
    CHECK(r[0][1] == 112);
    CHECK(r[1][0] == 204);
    CHECK(r[1][1] == 290);

    free_matrix(a, 2);
    free_matrix(b, 2);
    free_matrix(r, 2);
}

TEST_CASE("multiply_matrices: 1x3 * 3x1 (dot product)", "[matrix]")
{
    // [1 2 3] * [4]  = [1*4 + 2*5 + 3*6] = [32]
    //           [5]
    //           [6]
    int** a = make_matrix(1, 3, {1, 2, 3});
    int** b = make_matrix(3, 1, {4, 5, 6});

    int** r = multiply_matrices(1, 3, 1, a, b);

    CHECK(r[0][0] == 32);

    free_matrix(a, 1);
    free_matrix(b, 3);
    free_matrix(r, 1);
}

TEST_CASE("multiply_matrices: identity matrix", "[matrix]")
{
    // A * I = A
    int** a = make_matrix(2, 2, {3, 7, 2, 5});
    int** identity = make_matrix(2, 2, {1, 0, 0, 1});

    int** r = multiply_matrices(2, 2, 2, a, identity);

    CHECK(r[0][0] == 3);
    CHECK(r[0][1] == 7);
    CHECK(r[1][0] == 2);
    CHECK(r[1][1] == 5);

    free_matrix(a, 2);
    free_matrix(identity, 2);
    free_matrix(r, 2);
}

TEST_CASE("multiply_matrices: zero matrix gives all zeros", "[matrix]")
{
    int** a = make_matrix(2, 2, {5, 6, 7, 8});
    int** z = make_matrix(2, 2, {0, 0, 0, 0});

    int** r = multiply_matrices(2, 2, 2, a, z);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            CHECK(r[i][j] == 0);

    free_matrix(a, 2);
    free_matrix(z, 2);
    free_matrix(r, 2);
}

TEST_CASE("multiply_matrices: 2x3 * 3x2 non-square", "[matrix]")
{
    // [1 2 3] * [7 8]  = [1*7+2*9+3*11  1*8+2*10+3*12] = [58  64]
    // [4 5 6]   [9 10]   [4*7+5*9+6*11  4*8+5*10+6*12]   [139 154]
    //           [11 12]
    int** a = make_matrix(2, 3, {1, 2, 3, 4, 5, 6});
    int** b = make_matrix(3, 2, {7, 8, 9, 10, 11, 12});

    int** r = multiply_matrices(2, 3, 2, a, b);

    CHECK(r[0][0] == 58);
    CHECK(r[0][1] == 64);
    CHECK(r[1][0] == 139);
    CHECK(r[1][1] == 154);

    free_matrix(a, 2);
    free_matrix(b, 3);
    free_matrix(r, 2);
}
