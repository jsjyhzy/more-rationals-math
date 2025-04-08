#include "more_rationals_math.h"
#include "auxiliary.hpp"
#include "debugger.hpp"

mpq_class arctan(const mpq_class& x) {
    mpq_class x2 = x * x;

    debug_printf("When calculate tan^-1(x), x^2 is calculated as: %\n", x2);

    mpq_class diviser, deductor;
    diviser = constants::ODD_NUMBERS[default_continued_fraction_truncate_depth];

    #ifdef DEBUG_PRINT_MORE
    debug_printf("When calculate tan^-1(x), initial diviser is calculated as: %\n", diviser);
    #endif

    for (auto i = default_continued_fraction_truncate_depth; i > 0; i--)
    {
        deductor = constants::SQUARED_NATURE_NUMBERS[i - 1] * x2 / diviser;
        diviser = constants::ODD_NUMBERS[i - 1] + deductor;
        #ifdef DEBUG_PRINT_MORE
        debug_printf("When calculate tan^-1(x), the %d-th deductor is calculated as: %\n", i, deductor);
        debug_printf("When calculate tan^-1(x), the %d-th diviser is calculated as: %\n", i, diviser);
        #endif

        deductor = diviser;
    }
    return x / diviser;
};

void mpq_arctan(mpq_t arctanx, const mpq_t x)
{
    return c_style_uniary_operator<arctan>(arctanx, x);
};

static const mpq_class PI = [](){
    mpq_class one_five(1, 5);
    mpq_class one_twothreenine(1, 239);
    mpq_class result = 16 * arctan(one_five) - 4 * arctan(one_twothreenine);
    return result;
}();

mpq_class arccos(const mpq_class& x) {
    if (x == 0) { return PI / 2; };

    mpq_class tan_arccos = sqrt(1 - (x * x)) / x;
    debug_printf("When calculate arccos(x), x is: %\n", x);
    debug_printf("When calculate arccos(x), tan(arccos(x)) is calculated as: %\n", tan_arccos);

    mpq_class y = arctan(tan_arccos);
    if (y < 0) { y += PI; };
    return y;
};

void mpq_arccos(mpq_t arccosx, const mpq_t x)
{
    return c_style_uniary_operator<arccos>(arccosx, x);
};
