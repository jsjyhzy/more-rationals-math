#include <iostream>
#include "more_rationals_math.h"

typedef mpq_class (*op)(const mpq_class&);
typedef double (*ref_op)(double);
template <op op_to_test, ref_op op_referenced>
int result_is_good_approx(int argc, char** argv)
{
    mpq_class x;
    x.set_str(argv[1], 10);
    auto approx_x = x.get_d();

    mpq_class fx = op_to_test(x);
    auto approx_fx = op_referenced(approx_x);

    auto delta = approx_fx - fx.get_d();
    delta = delta < 0 ? - delta : delta;

    if (delta > 1e-14)
    {
        std::cout << argv[0] << "\t:f(1) = " << fx.get_d() << "\t Approx is " << approx_fx << std::endl;
        return 1;
    }

    return 0;

};