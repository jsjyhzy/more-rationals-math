#include <vector>
#include <gmpxx.h>

#include "auxiliary.hpp"

unsigned int default_continued_fraction_truncate_depth = DEFAULT_TRUNCATE_DEPTH;

mpq_class* _linspace(long (*fx)(long x), unsigned long end_before, unsigned long start_at = 1)
{
    auto ret = new mpq_class[MAX_TRUNCATE_DEPTH + 2];
    unsigned long idx = 0;
    for (auto i = start_at; i < end_before; i++)
    {
        ret[idx] = fx(i);
        idx++;
    };
    return ret;
};

linespace::linespace()
: ODD_NUMBERS(_linspace([](long x){ return 2 * x - 1; }, MAX_TRUNCATE_DEPTH + 2))
, POSITIVE_NATURE_NUMBERS(_linspace([](long x){ return x; }, MAX_TRUNCATE_DEPTH + 2))
, SQUARED_NATURE_NUMBERS(_linspace([](long x){ return x * x; }, MAX_TRUNCATE_DEPTH + 2))
{};

const linespace mpq_integers = linespace();

