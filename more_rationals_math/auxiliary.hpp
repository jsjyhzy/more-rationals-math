#include <vector>
#include <gmpxx.h>

namespace constants
{
    // compile time const

    constexpr unsigned int MAX_TRUNCATE_DEPTH = 64;
    constexpr unsigned int DEFAULT_TRUNCATE_DEPTH = 24;

    // runtime const

    template <typename T>
    std::vector<mpq_class> nature_linspace(T (*fx)(long x), unsigned long end_before, unsigned long start_at = 1)
    {
        std::vector<mpq_class> ret;
        for (auto i = start_at; i < end_before; i++)
        {
            mpq_class y = fx(i);
            ret.push_back(y);
        };
        return ret;
    };

    static const std::vector<mpq_class> ODD_NUMBERS = nature_linspace<long>([](long x){ return 2 * x - 1; }, MAX_TRUNCATE_DEPTH + 2);
    static const std::vector<mpq_class> POSITIVE_NATURE_NUMBERS = nature_linspace<long>([](long x){ return x; }, MAX_TRUNCATE_DEPTH + 2);
    const auto& NATURE_NUMBERS = POSITIVE_NATURE_NUMBERS;
    const auto& ONE = NATURE_NUMBERS[0];
    const auto& TWO = NATURE_NUMBERS[1];
    static const std::vector<mpq_class> SQUARED_NATURE_NUMBERS = nature_linspace<long>([](long x){ return x * x; }, MAX_TRUNCATE_DEPTH + 2);

};

unsigned int default_continued_fraction_truncate_depth = constants::DEFAULT_TRUNCATE_DEPTH;

typedef mpq_class (*uniary_operator)(const mpq_class&);
template <uniary_operator op>
void c_style_uniary_operator(mpq_t c_fx, const mpq_t c_x)
{
    auto fx = op((mpq_class) c_x);
    auto literal_repr = fx.get_str(10);
    mpq_set_str(c_fx, literal_repr.c_str(), 10);
}