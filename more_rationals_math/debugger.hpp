#ifdef DEBUG
#include <initializer_list>
#include <type_traits>
template <typename T, typename MP>
void debug_printf_impl(const char* fmt, std::initializer_list<T> args)
{
    constexpr const char* number_fmt = [](){
        if constexpr (std::is_base_of_v<mpq_class, MP>)
        {
            return "%16Qd";
        } else if constexpr (std::is_base_of_v<mpf_class, MP>)
        {
            return "%24.18Ff";
        }
    }();

    char* buf;
    auto arg = args.begin();
    std::string whole_line;
    for (; *fmt != '\0'; fmt++)
    {
        if (*fmt != '%')
        {
            whole_line += *fmt;
            continue;
        }
        
        gmp_asprintf(&buf, number_fmt, *arg);
        whole_line.append(buf);
        free(buf);
        arg++;
    }

    std::cout << whole_line;
}

#ifdef DEBUG_PRINT_FLOAT
#define debug_printf(fmt, ...) debug_printf_impl<mpq_class, mpf_class>(fmt, {__VA_ARGS__})
#else
#define debug_printf(fmt, ...) debug_printf_impl<mpq_class, mpq_class>(fmt, {__VA_ARGS__})
#endif
#else
#define debug_printf(fmt, ...)
#endif
