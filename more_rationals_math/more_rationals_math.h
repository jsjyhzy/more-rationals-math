#pragma once
#include <gmp.h>

extern unsigned int default_continued_fraction_truncate_depth;

#ifdef __cplusplus
#define __safer_enum struct
#else
#define __safer_enum
#endif

enum __safer_enum mathematical_constant {PI};

#ifdef __cplusplus
extern "C" {
#endif

void mpq_set_constant(mpq_t x, const mathematical_constant who);

void mpq_sqrt(mpq_t sqrtx, const mpq_t x);
void mpq_tan(mpq_t tanx, const mpq_t x);
void mpq_sin(mpq_t sinx, const mpq_t x);
void mpq_cos(mpq_t cosx, const mpq_t x);
void mpq_arctan(mpq_t arctanx, const mpq_t x);
void mpq_arccos(mpq_t arccosx, const mpq_t x);

#ifdef __cplusplus
}

#ifndef RATIONALS_MATH_C_INTERFACE_ONLY

#include <gmpxx.h>

struct mathematical_constant_t
{
    mpq_class repr;

    mathematical_constant_t() = delete;
    mathematical_constant_t(const mathematical_constant& type);
    explicit operator mpq_class() const { return mpq_class(repr); };
};

mpq_class sqrt(const mpq_class& x);
mpq_class tan(const mpq_class& x);
mpq_class sin(const mpq_class& x);
mpq_class cos(const mpq_class& x);
mpq_class arctan(const mpq_class& x);
mpq_class arccos(const mpq_class& x);

#endif

#endif
