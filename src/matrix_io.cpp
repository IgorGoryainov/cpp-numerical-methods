#include "matrix_io.h"
#include "matrix.h"
#include <fstream>
#include <string>

bool check_matrix_file_input(const std::string& file_name)
{
    std::ifstream ifs(file_name);
    int m, n, k;
    ifs >> m >> n >> k;
    return check_matrix_input(m, n, k) != 0;
}

void load_matrix_report(int failed)
{
    std::ofstream ofs("matrix_report.txt", std::ios::trunc);
    if (!failed)
        ofs << "Input correct, task finished successfully";
    else
        ofs << "Input incorrect, task failed";
}

void process_matrix_file(int num)
{
    std::string input_name  = "data/matrix_input_" + std::to_string(num) + ".txt";
    std::string output_name = "matrix_output_"     + std::to_string(num) + ".txt";

    std::ofstream ofs(output_name, std::ios::trunc);

    if (!check_matrix_file_input(input_name))
    {
        std::ifstream ifs(input_name);
        int m, n, k;
        ifs >> m >> n >> k;

        int** mat1 = new int*[m];
        for (int i = 0; i < m; i++)
            mat1[i] = new int[n];

        int** mat2 = new int*[n];
        for (int i = 0; i < n; i++)
            mat2[i] = new int[k];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ifs >> mat1[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                ifs >> mat2[i][j];

        int** result = multiply_matrices(m, n, k, mat1, mat2);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < k; j++)
                ofs << result[i][j] << " ";
            ofs << "\n";
        }

        for (int i = 0; i < m; i++) delete[] mat1[i];
        delete[] mat1;
        for (int i = 0; i < n; i++) delete[] mat2[i];
        delete[] mat2;
        for (int i = 0; i < m; i++) delete[] result[i];
        delete[] result;
    }
    else
    {
        ofs << "Incorrect input";
    }
}
