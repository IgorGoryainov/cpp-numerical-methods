#include <iostream>
#include <cmath>
#include "series.h"
#include "series_io.h"
#include "matrix_io.h"
#include "matrix.h"

int main()
{
    // Task 1: cosh(x) approximation via Taylor series
    long double x, e;
    std::cin >> x >> e;

    load_series_report(check_series_input(x, e));
    if (check_series_input(x, e) == 0)
    {
        SeriesResult result = cosh_series(x, e);
        std::cout << "Approximate value: " << result.approximate << std::endl;
        std::cout << "Exact value:       " << result.exact << std::endl;
        std::cout << "Absolute error:    " << result.absolute_error << std::endl;
        std::cout << "Relative error:    " << result.relative_error;
    }
    else
    {
        std::cout << "Incorrect input";
    }
    std::cout << std::endl;

    // Process input files for Task 1
    for (int i = 1; i < 3; i++)
        process_series_file(i);

    // Task 2: matrix multiplication
    int m, n, k;
    std::cin >> m >> n >> k;

    load_matrix_report(check_matrix_input(m, n, k));
    if (check_matrix_input(m, n, k) != 1)
    {
        int** mat1 = new int*[m];
        for (int i = 0; i < m; i++)
            mat1[i] = new int[n];

        int** mat2 = new int*[n];
        for (int i = 0; i < n; i++)
            mat2[i] = new int[k];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                std::cin >> mat1[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                std::cin >> mat2[i][j];

        int** result_mat = multiply_matrices(m, n, k, mat1, mat2);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < k; j++)
                std::cout << result_mat[i][j] << " ";
            std::cout << std::endl;
        }

        for (int i = 0; i < m; i++) delete[] mat1[i];
        delete[] mat1;
        for (int i = 0; i < n; i++) delete[] mat2[i];
        delete[] mat2;
        for (int i = 0; i < m; i++) delete[] result_mat[i];
        delete[] result_mat;
    }
    else
    {
        std::cout << "Incorrect input";
    }

    // Process input files for Task 2
    for (int i = 1; i < 3; i++)
        process_matrix_file(i);

    return 0;
}
