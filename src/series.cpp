#include "series.h"
#include <cmath>

SeriesResult cosh_series(long double x, long double epsilon)
{
    long double term = 1.0L;
    long double approx = 0.0L;
    int n = 0;

    while (fabsl(term) > epsilon)
    {
        approx += term;
        n++;
        term = (term * x * x) / (2 * n * (2 * n - 1));
    }

    long double exact = coshl(x);
    long double abs_error = fabsl(exact - approx);
    long double rel_error = (exact != 0.0L) ? fabsl(abs_error / exact) : 0.0L;

    return { approx, exact, abs_error, rel_error };
}

int check_series_input(long double /*x*/, long double epsilon)
{
    return (epsilon >= 1.0L) ? 1 : 0;
}
