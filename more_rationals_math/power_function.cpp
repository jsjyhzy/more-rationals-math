#include "more_rationals_math.h"
#include "auxiliary.hpp"
#include "debugger.hpp"

mpq_class sqrt(const mpq_class& x)
{
    if (x < 0) { throw  std::domain_error("sqrt of negative number"); };

    if (x < 1)
    {
        debug_printf("When sqrt(x), x is lower than 1, flipped: %\n", x);
        return 1 / sqrt(1 / x);
    };

    mpf_class float_floor_of_sqrt = floor(sqrt((mpf_class) x));
    mpq_class floor_of_sqrt = float_floor_of_sqrt.get_si();

    debug_printf("When sqrt(x), the low bond of sqrt(x) is calculated as: %\n", floor_of_sqrt);

    const auto squared_floor_of_sqrt = floor_of_sqrt * floor_of_sqrt;
    const auto addition = mpq_integers.TWO() * floor_of_sqrt;
    const auto dividend = x - squared_floor_of_sqrt;

    mpq_class divider = addition;

    for (auto i = 0; i < default_continued_fraction_truncate_depth; i++)
    {
        divider = addition + (dividend / divider);
    }

    return floor_of_sqrt + dividend / divider;
};

void mpq_sqrt(mpq_t sqrtx, const mpq_t x)
{
    return c_style_uniary_operator<sqrt>(sqrtx, x);
};
