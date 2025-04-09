#include "more_rationals_math.h"
#include "auxiliary.hpp"
#include "debugger.hpp"

mpq_class tan(const mpq_class& x) {
    mpq_class x2 = x * x;

    debug_printf("When calculate tan(x), x^2 is calculated as: %\n", x2);

    mpq_class diviser, deductor;
    diviser = mpq_integers.ODD_NUMBERS[default_continued_fraction_truncate_depth];

    for (auto i = default_continued_fraction_truncate_depth; i > 0; i--)
    {
        deductor = x2 / diviser;
        diviser = mpq_integers.ODD_NUMBERS[i - 1] - deductor;
        #ifdef DEBUG_PRINT_MORE
        debug_printf("When calculate tan(x), the %-th deductor is calculated as: %\n", i, deductor);
        debug_printf("When calculate tan(x), the %-th diviser is calculated as: %\n", i, diviser);
        #endif

        deductor = diviser;
    }
    return x / diviser;
};

void mpq_tan(mpq_t tanx, const mpq_t x)
{
    return c_style_uniary_operator<tan>(tanx, x);
};

mpq_class sin (const mpq_class& x) {
    mpq_class half_x = x / mpq_integers.TWO();

    mpq_class tan_half_x = tan(half_x);

    mpq_class dividend, divider;
    dividend = mpq_integers.TWO() * tan_half_x;
    divider = mpq_integers.ONE() + tan_half_x * tan_half_x;

    return dividend / divider;
};

void mpq_sin(mpq_t sinx, const mpq_t x)
{
    return c_style_uniary_operator<sin>(sinx, x);
};

mpq_class cos(const mpq_class& x) {
        mpq_class half_x = x / mpq_integers.TWO();

        mpq_class tan_half_x = tan(half_x);

        mpq_class dividend, divider;
        mpq_class squared_tan_half_x = tan_half_x * tan_half_x;
        dividend = mpq_integers.ONE() - squared_tan_half_x;
        divider = mpq_integers.ONE() + squared_tan_half_x;

        return dividend / divider;
    };

void mpq_cos(mpq_t cosx, const mpq_t x)
{
    return c_style_uniary_operator<cos>(cosx, x);
};
