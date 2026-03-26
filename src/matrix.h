#pragma once

// Multiplies mat1 (m x n) by mat2 (n x k), returns a newly allocated (m x k) matrix.
// Caller is responsible for freeing each row and the outer pointer.
int**         multiply_matrices(int m, int n, int k, int**         mat1, int**         mat2);
long int**    multiply_matrices(int m, int n, int k, long int**    mat1, long int**    mat2);
float**       multiply_matrices(int m, int n, int k, float**       mat1, float**       mat2);
double**      multiply_matrices(int m, int n, int k, double**      mat1, double**      mat2);
long double** multiply_matrices(int m, int n, int k, long double** mat1, long double** mat2);

// Returns 1 if any dimension is less than 1, 0 otherwise.
int check_matrix_input(int m, int n, int k);
