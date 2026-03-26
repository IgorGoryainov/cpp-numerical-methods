#pragma once
#include <string>

// Returns false if the file input is valid, true if invalid.
bool check_series_file_input(const std::string& file_name);

// Writes a one-line status to report.txt.
void load_series_report(int failed);

// Reads data/input_N.txt, runs cosh_series, writes result to output_N.txt.
void process_series_file(int num);
