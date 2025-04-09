#include <vector>
#include <gmpxx.h>

// compile time const

constexpr unsigned int MAX_TRUNCATE_DEPTH = 64;
constexpr unsigned int DEFAULT_TRUNCATE_DEPTH = 24;

struct linespace
{
    linespace();
    const mpq_class *ODD_NUMBERS;
    const mpq_class *POSITIVE_NATURE_NUMBERS;
    const mpq_class *SQUARED_NATURE_NUMBERS;

    const mpq_class& ONE(void) const { return POSITIVE_NATURE_NUMBERS[0]; };
    const mpq_class& TWO(void) const { return POSITIVE_NATURE_NUMBERS[1]; };
};

extern const linespace mpq_integers;

typedef mpq_class (*uniary_operator)(const mpq_class&);
template <uniary_operator op>
void c_style_uniary_operator(mpq_t c_fx, const mpq_t c_x)
{
    auto fx = op((mpq_class) c_x);
    auto literal_repr = fx.get_str(10);
    mpq_set_str(c_fx, literal_repr.c_str(), 10);
}