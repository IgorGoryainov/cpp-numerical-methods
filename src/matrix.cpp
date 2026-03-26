#include "matrix.h"

int check_matrix_input(int m, int n, int k)
{
    return (m < 1 || n < 1 || k < 1) ? 1 : 0;
}

int** multiply_matrices(int m, int n, int k, int** mat1, int** mat2)
{
    int** result = new int*[m];
    for (int i = 0; i < m; i++)
        result[i] = new int[k];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
        {
            int sum = 0;
            for (int p = 0; p < n; p++)
                sum += mat1[i][p] * mat2[p][j];
            result[i][j] = sum;
        }

    return result;
}

long int** multiply_matrices(int m, int n, int k, long int** mat1, long int** mat2)
{
    long int** result = new long int*[m];
    for (int i = 0; i < m; i++)
        result[i] = new long int[k];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
        {
            long int sum = 0;
            for (int p = 0; p < n; p++)
                sum += mat1[i][p] * mat2[p][j];
            result[i][j] = sum;
        }

    return result;
}

float** multiply_matrices(int m, int n, int k, float** mat1, float** mat2)
{
    float** result = new float*[m];
    for (int i = 0; i < m; i++)
        result[i] = new float[k];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
        {
            float sum = 0.0f;
            for (int p = 0; p < n; p++)
                sum += mat1[i][p] * mat2[p][j];
            result[i][j] = sum;
        }

    return result;
}

double** multiply_matrices(int m, int n, int k, double** mat1, double** mat2)
{
    double** result = new double*[m];
    for (int i = 0; i < m; i++)
        result[i] = new double[k];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
        {
            double sum = 0.0;
            for (int p = 0; p < n; p++)
                sum += mat1[i][p] * mat2[p][j];
            result[i][j] = sum;
        }

    return result;
}

long double** multiply_matrices(int m, int n, int k, long double** mat1, long double** mat2)
{
    long double** result = new long double*[m];
    for (int i = 0; i < m; i++)
        result[i] = new long double[k];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
        {
            long double sum = 0.0L;
            for (int p = 0; p < n; p++)
                sum += mat1[i][p] * mat2[p][j];
            result[i][j] = sum;
        }

    return result;
}
