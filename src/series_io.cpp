#include "series_io.h"
#include "series.h"
#include <fstream>
#include <string>

bool check_series_file_input(const std::string& file_name)
{
    std::ifstream ifs(file_name);
    long double x, epsilon;
    ifs >> x >> epsilon;
    return check_series_input(x, epsilon) != 0;
}

void load_series_report(int failed)
{
    std::ofstream ofs("report.txt", std::ios::trunc);
    if (!failed)
        ofs << "Input correct, task finished successfully";
    else
        ofs << "Input incorrect, task failed";
}

void process_series_file(int num)
{
    std::string input_name  = "data/input_"  + std::to_string(num) + ".txt";
    std::string output_name = "output_" + std::to_string(num) + ".txt";

    std::ofstream ofs(output_name, std::ios::trunc);

    if (!check_series_file_input(input_name))
    {
        std::ifstream ifs(input_name);
        long double x, epsilon;
        ifs >> x >> epsilon;

        SeriesResult result = cosh_series(x, epsilon);
        ofs << "Approximate value: " << result.approximate << "\n"
            << "Exact value:       " << result.exact << "\n"
            << "Absolute error:    " << result.absolute_error << "\n"
            << "Relative error:    " << result.relative_error;
    }
    else
    {
        ofs << "Incorrect input";
    }
}
