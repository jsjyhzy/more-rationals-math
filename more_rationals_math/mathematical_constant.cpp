#include "more_rationals_math.h"


mathematical_constant_t::mathematical_constant_t(const mathematical_constant& type)
{
    switch (type)
    {
    case mathematical_constant::PI:
        // use Machin-like formula
        (*this).repr = 16 * arctan(1_mpq / 5) - 4 * arctan(1_mpq / 239);
        break;
    
    default:
        break;
    }

};

void mpq_set_constant(mpq_t x, const mathematical_constant who)
{
    auto x_ = mpq_class(mathematical_constant_t(who));
    mpq_set_str(x, x_.get_str(10).c_str(), 10);
};