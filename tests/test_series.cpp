#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <cmath>
#include "series.h"

using Catch::Matchers::WithinRel;
using Catch::Matchers::WithinAbs;

TEST_CASE("check_series_input validates epsilon", "[series]")
{
    SECTION("valid: epsilon less than 1")
    {
        CHECK(check_series_input(1.0L, 0.001L) == 0);
        CHECK(check_series_input(0.0L, 1e-10L) == 0);
        CHECK(check_series_input(-5.0L, 0.5L) == 0);
    }

    SECTION("invalid: epsilon equal to 1")
    {
        CHECK(check_series_input(0.0L, 1.0L) == 1);
    }

    SECTION("invalid: epsilon greater than 1")
    {
        CHECK(check_series_input(0.0L, 2.0L) == 1);
        CHECK(check_series_input(10.0L, 100.0L) == 1);
    }
}

TEST_CASE("cosh_series approximates cosh(x)", "[series]")
{
    SECTION("cosh(0) = 1")
    {
        auto r = cosh_series(0.0L, 1e-9L);
        CHECK_THAT((double)r.approximate, WithinAbs(1.0, 1e-6));
        CHECK_THAT((double)r.absolute_error, WithinAbs(0.0, 1e-6));
    }

    SECTION("cosh(1) matches std::cosh")
    {
        auto r = cosh_series(1.0L, 1e-9L);
        double expected = std::cosh(1.0);
        CHECK_THAT((double)r.approximate, WithinRel(expected, 1e-6));
        CHECK_THAT((double)r.exact,       WithinRel(expected, 1e-12));
    }

    SECTION("cosh(-x) == cosh(x): function is even")
    {
        auto pos = cosh_series( 3.0L, 1e-9L);
        auto neg = cosh_series(-3.0L, 1e-9L);
        CHECK_THAT((double)pos.approximate, WithinRel((double)neg.approximate, 1e-9));
    }

    SECTION("absolute error is non-negative")
    {
        auto r = cosh_series(5.0L, 1e-6L);
        CHECK(r.absolute_error >= 0.0L);
        CHECK(r.relative_error >= 0.0L);
    }

    SECTION("tighter epsilon produces smaller error")
    {
        auto coarse = cosh_series(2.0L, 1e-3L);
        auto fine   = cosh_series(2.0L, 1e-9L);
        CHECK(fine.absolute_error <= coarse.absolute_error + 1e-4L);
    }

    SECTION("large x still returns a finite result within tolerance")
    {
        auto r = cosh_series(10.0L, 1e-6L);
        double expected = std::cosh(10.0);
        CHECK_THAT((double)r.exact, WithinRel(expected, 1e-9));
    }
}
