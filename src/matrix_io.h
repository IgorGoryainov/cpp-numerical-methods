#pragma once
#include <string>

// Returns true if the file's m/n/k values are invalid (any dimension < 1).
bool check_matrix_file_input(const std::string& file_name);

// Writes a one-line status to matrix_report.txt.
void load_matrix_report(int failed);

// Reads data/matrix_input_N.txt, multiplies, writes to matrix_output_N.txt.
void process_matrix_file(int num);
