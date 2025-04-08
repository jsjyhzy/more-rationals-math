#include <iostream>
#include "more_rationals_math.h"
#include "test_approx.hpp"

#include <cmath>

int main(int argc, char** argv)
{
    return result_is_good_approx<sqrt, sqrt>(argc, argv);
}