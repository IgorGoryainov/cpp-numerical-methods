#pragma once

struct SeriesResult
{
    long double approximate;
    long double exact;
    long double absolute_error;
    long double relative_error;
};

// Approximates cosh(x) using its Taylor series until each term is smaller than epsilon.
// Returns approximate value, exact value (from std::cosh), and both error metrics.
SeriesResult cosh_series(long double x, long double epsilon);

// Validates that epsilon < 1 (epsilon >= 1 makes the series trivially useless).
// Returns 0 on valid input, 1 on invalid.
int check_series_input(long double x, long double epsilon);
