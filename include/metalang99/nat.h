/**
 * @file
 * Natural numbers: [0; 255].
 *
 * Most of the time, natural numbers are used for iteration; they are not meant for CPU-bound tasks
 * such as Fibonacci numbers or factorials.
 */

#ifndef ML99_NAT_H
#define ML99_NAT_H

#include <metalang99/priv/bool.h>

#include <metalang99/nat/dec.h>
#include <metalang99/nat/div.h>
#include <metalang99/nat/eq.h>
#include <metalang99/nat/inc.h>

#include <metalang99/lang.h>

/**
 * \f$x + 1\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 6
 * ML99_inc(ML99_QUOTE(5))
 * @endcode
 *
 * @note If @p x is #ML99_NAT_MAX, the result is 0.
 */
#define ML99_inc(x) ML99_call(ML99_inc, x)

/**
 * \f$x - 1\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 4
 * ML99_dec(ML99_QUOTE(5))
 * @endcode
 *
 * @note If @p x is 0, the result is #ML99_NAT_MAX.
 */
#define ML99_dec(x) ML99_call(ML99_dec, x)

/**
 * Matches @p x against the two cases: if it is zero or positive.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * #define MATCH_Z_IMPL()  ML99_QUOTE(Billie)
 * #define MATCH_S_IMPL(x) ML99_QUOTE(Jean ~ x)
 *
 * // Billie
 * ML99_natMatch(ML99_QUOTE(0), ML99_QUOTE(MATCH_))
 *
 * // Jean ~ 122
 * ML99_natMatch(ML99_QUOTE(123), ML99_QUOTE(MATCH_))
 * @endcode
 *
 * @note This function calls @p f with #ML99_call, so no partial application occurs, and so
 * arity specifiers are not needed.
 */
#define ML99_natMatch(x, matcher) ML99_call(ML99_natMatch, x, matcher)

/**
 * The same as #ML99_natMatch but provides additional arguments to all branches.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * #define MATCH_Z_IMPL(x, y, z)    ML99_QUOTE(Billie ~ x y z)
 * #define MATCH_S_IMPL(n, x, y, z) ML99_QUOTE(Jean ~ n ~ x y z)
 *
 * // Billie ~ 1 2 3
 * ML99_natMatchWithArgs(ML99_QUOTE(0), ML99_QUOTE(MATCH_), ML99_QUOTE(1, 2, 3))
 *
 * // Jean ~ 122 ~ 1 2 3
 * ML99_natMatchWithArgs(ML99_QUOTE(123), ML99_QUOTE(MATCH_), ML99_QUOTE(1, 2, 3))
 * @endcode
 */
#define ML99_natMatchWithArgs(x, matcher, ...)                                                     \
    ML99_call(ML99_natMatchWithArgs, x, matcher, __VA_ARGS__)

/**
 * \f$x = y\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 1
 * ML99_natEq(ML99_QUOTE(5), ML99_QUOTE(5))
 *
 * // 0
 * ML99_natEq(ML99_QUOTE(3), ML99_QUOTE(8))
 * @endcode
 */
#define ML99_natEq(x, y) ML99_call(ML99_natEq, x, y)

/**
 * \f$x \neq y\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 0
 * ML99_natNeq(ML99_QUOTE(5), ML99_QUOTE(5))
 *
 * // 1
 * ML99_natNeq(ML99_QUOTE(3), ML99_QUOTE(8))
 * @endcode
 */
#define ML99_natNeq(x, y) ML99_call(ML99_natNeq, x, y)

/**
 * \f$x > y\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 1
 * ML99_greater(ML99_QUOTE(8), ML99_QUOTE(3))
 *
 * // 0
 * ML99_greater(ML99_QUOTE(3), ML99_QUOTE(8))
 * @endcode
 */
#define ML99_greater(x, y) ML99_call(ML99_greater, x, y)

/**
 * \f$x \geq y\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 1
 * ML99_greaterEq(ML99_QUOTE(8), ML99_QUOTE(8))
 *
 * // 0
 * ML99_greaterEq(ML99_QUOTE(3), ML99_QUOTE(8))
 * @endcode
 */
#define ML99_greaterEq(x, y) ML99_call(ML99_greaterEq, x, y)

/**
 * \f$x < y\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 1
 * ML99_lesser(ML99_QUOTE(3), ML99_QUOTE(8))
 *
 * // 0
 * ML99_lesser(ML99_QUOTE(8), ML99_QUOTE(3))
 * @endcode
 */
#define ML99_lesser(x, y) ML99_call(ML99_lesser, x, y)

/**
 * \f$x \leq y\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 1
 * ML99_lesserEq(ML99_QUOTE(8), ML99_QUOTE(8))
 *
 * // 0
 * ML99_lesserEq(ML99_QUOTE(8), ML99_QUOTE(3))
 * @endcode
 */
#define ML99_lesserEq(x, y) ML99_call(ML99_lesserEq, x, y)

/**
 * \f$x + y\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 11
 * ML99_add(ML99_QUOTE(5), ML99_QUOTE(6))
 * @endcode
 */
#define ML99_add(x, y) ML99_call(ML99_add, x, y)

/**
 * \f$x - y\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 6
 * ML99_sub(ML99_QUOTE(11), ML99_QUOTE(5))
 * @endcode
 */
#define ML99_sub(x, y) ML99_call(ML99_sub, x, y)

/**
 * \f$x * y\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 12
 * ML99_mul(ML99_QUOTE(3), ML99_QUOTE(4))
 * @endcode
 */
#define ML99_mul(x, y) ML99_call(ML99_mul, x, y)

/**
 * \f$\frac{x}{y}\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 3
 * ML99_div(ML99_QUOTE(12), ML99_QUOTE(4))
 * @endcode
 *
 * @note A compile-time error if \f$\frac{x}{y}\f$ is not a natural number.
 */
#define ML99_div(x, y) ML99_call(ML99_div, x, y)

/**
 * Like #ML99_div but returns `ML99_nothing()` is @p x is not divisible by @p y,
 * otherwise `ML99_just(result)`.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // ML99_just(3)
 * ML99_divChecked(ML99_QUOTE(12), ML99_QUOTE(4))
 *
 * // ML99_nothing()
 * ML99_divChecked(ML99_QUOTE(14), ML99_QUOTE(5))
 *
 * // ML99_nothing()
 * ML99_divChecked(ML99_QUOTE(1), ML99_QUOTE(0))
 * @endcode
 */
#define ML99_divChecked(x, y) ML99_call(ML99_divChecked, x, y)

/**
 * Computes the remainder of division.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 2
 * ML99_mod(ML99_QUOTE(8), ML99_QUOTE(3))
 * @endcode
 *
 * @note A compile-time error if @p y is 0.
 */
#define ML99_mod(x, y) ML99_call(ML99_mod, x, y)

/**
 * \f$x + y + z\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 15
 * ML99_add3(ML99_QUOTE(1), ML99_QUOTE(6), ML99_QUOTE(8))
 * @endcode
 */
#define ML99_add3(x, y, z) ML99_call(ML99_add3, x, y, z)

/**
 * \f$x - y - z\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 3
 * ML99_sub3(ML99_QUOTE(8), ML99_QUOTE(2), ML99_QUOTE(3))
 * @endcode
 */
#define ML99_sub3(x, y, z) ML99_call(ML99_sub3, x, y, z)

/**
 * \f$x * y * z\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 24
 * ML99_mul3(ML99_QUOTE(2), ML99_QUOTE(3), ML99_QUOTE(4))
 * @endcode
 */
#define ML99_mul3(x, y, z) ML99_call(ML99_mul3, x, y, z)

/**
 * \f$\frac{(\frac{x}{y})}{z}\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 5
 * ML99_div(ML99_QUOTE(30), ML99_QUOTE(3), ML99_QUOTE(2))
 * @endcode
 *
 * @note A compile-time error if \f$\frac{(\frac{x}{y})}{z}\f$ is not a natural number.
 */
#define ML99_div3(x, y, z) ML99_call(ML99_div3, x, y, z)

/**
 * \f$min(x, y)\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 5
 * ML99_min(ML99_QUOTE(5), ML99_QUOTE(7))
 * @endcode
 */
#define ML99_min(x, y) ML99_call(ML99_min, x, y)

/**
 * \f$max(x, y)\f$
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * // 7
 * ML99_max(ML99_QUOTE(5), ML99_QUOTE(7))
 * @endcode
 */
#define ML99_max(x, y) ML99_call(ML99_max, x, y)

/**
 * Emits a fatal error if @p x is not a natural number, otherwise results in emptiness.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/nat.h>
 *
 * #define F_IMPL(x) ML99_TERMS(ML99_assertIsNat(ML99_QUOTE(x)), ML99_inc(ML99_QUOTE(x)))
 *
 * // 6
 * ML99_call(F, ML99_QUOTE(5))
 *
 * // A compile-time number mismatch error.
 * ML99_call(F, ML99_QUOTE(blah))
 * @endcode
 */
#define ML99_assertIsNat(x) ML99_call(ML99_assertIsNat, x)

#define ML99_INC(x)            ML99_PRIV_INC(x)
#define ML99_DEC(x)            ML99_PRIV_DEC(x)
#define ML99_NAT_EQ(x, y)      ML99_PRIV_NAT_EQ(x, y)
#define ML99_NAT_NEQ(x, y)     ML99_PRIV_NOT(ML99_NAT_EQ(x, y))
#define ML99_DIV_CHECKED(x, y) ML99_PRIV_DIV_CHECKED(x, y)

/**
 * The maximum value of a natural number, currently 255.
 */
#define ML99_NAT_MAX 255

#ifndef DOXYGEN_IGNORE

// Pattern matching {

#define ML99_natMatch_IMPL(x, matcher)                                                             \
    ML99_PRIV_IF(                                                                                  \
        ML99_NAT_EQ(x, 0),                                                                         \
        ML99_callUneval(matcher##Z, ),                                                             \
        ML99_callUneval(matcher##S, ML99_DEC(x)))

#define ML99_natMatchWithArgs_IMPL(x, matcher, ...)                                                \
    ML99_PRIV_IF(                                                                                  \
        ML99_NAT_EQ(x, 0),                                                                         \
        ML99_callUneval(matcher##Z, __VA_ARGS__),                                                  \
        ML99_callUneval(matcher##S, ML99_DEC(x), __VA_ARGS__))
// } (Pattern matching)

// Comparison operators {

#define ML99_natEq_IMPL(x, y)  ML99_QUOTE(ML99_NAT_EQ(x, y))
#define ML99_natNeq_IMPL(x, y) ML99_QUOTE(ML99_NAT_NEQ(x, y))

#define ML99_lesser_IMPL(x, y)                                                                     \
    ML99_PRIV_IF(                                                                                  \
        ML99_NAT_EQ(y, 0),                                                                         \
        ML99_QUOTE(ML99_PRIV_FALSE()),                                                                      \
        ML99_PRIV_IF(                                                                              \
            ML99_NAT_EQ(x, ML99_DEC(y)),                                                           \
            ML99_QUOTE(ML99_PRIV_TRUE()),                                                                   \
            ML99_callUneval(ML99_lesser, x, ML99_DEC(y))))

#define ML99_lesserEq_IMPL(x, y) ML99_greaterEq_IMPL(y, x)

#define ML99_greater_IMPL(x, y) ML99_lesser_IMPL(y, x)
#define ML99_greaterEq_IMPL(x, y)                                                                  \
    ML99_PRIV_IF(ML99_NAT_EQ(x, y), ML99_QUOTE(ML99_PRIV_TRUE()), ML99_greater_IMPL(x, y))
// } (Comparison operators)

// Arithmetical operators {

#define ML99_inc_IMPL(x) ML99_QUOTE(ML99_INC(x))
#define ML99_dec_IMPL(x) ML99_QUOTE(ML99_DEC(x))

#define ML99_add_IMPL(x, y)                                                                        \
    ML99_PRIV_IF(ML99_NAT_EQ(y, 0), ML99_QUOTE(x), ML99_callUneval(ML99_add, ML99_INC(x), ML99_DEC(y)))
#define ML99_sub_IMPL(x, y)                                                                        \
    ML99_PRIV_IF(ML99_NAT_EQ(y, 0), ML99_QUOTE(x), ML99_callUneval(ML99_sub, ML99_DEC(x), ML99_DEC(y)))
#define ML99_mul_IMPL(x, y)                                                                        \
    ML99_PRIV_IF(ML99_NAT_EQ(y, 0), ML99_QUOTE(0), ML99_add(ML99_QUOTE(x), ML99_callUneval(ML99_mul, x, ML99_DEC(y))))

#define ML99_add3_IMPL(x, y, z) ML99_add(ML99_add_IMPL(x, y), ML99_QUOTE(z))
#define ML99_sub3_IMPL(x, y, z) ML99_sub(ML99_sub_IMPL(x, y), ML99_QUOTE(z))
#define ML99_mul3_IMPL(x, y, z) ML99_mul(ML99_mul_IMPL(x, y), ML99_QUOTE(z))
#define ML99_div3_IMPL(x, y, z) ML99_div(ML99_div_IMPL(x, y), ML99_QUOTE(z))

#define ML99_min_IMPL(x, y) ML99_call(ML99_if, ML99_lesser_IMPL(x, y), ML99_QUOTE(x, y))
#define ML99_max_IMPL(x, y) ML99_call(ML99_if, ML99_lesser_IMPL(x, y), ML99_QUOTE(y, x))

#define ML99_divChecked_IMPL(x, y) ML99_QUOTE(ML99_DIV_CHECKED(x, y))

// ML99_mod_IMPL {

#define ML99_mod_IMPL(x, y)                                                                        \
    ML99_PRIV_IF(                                                                                  \
        ML99_NAT_EQ(y, 0),                                                                         \
        ML99_fatal(ML99_mod, modulo by 0),                                                         \
        ML99_PRIV_modAux_IMPL(x, y, 0))

#define ML99_PRIV_modAux_IMPL(x, y, acc)                                                           \
    ML99_PRIV_IF(                                                                                  \
        ML99_PRIV_OR(ML99_NAT_EQ(x, 0), ML99_IS_JUST(ML99_DIV_CHECKED(x, y))),                     \
        ML99_QUOTE(acc),                                                                                    \
        ML99_callUneval(ML99_PRIV_modAux, ML99_DEC(x), y, ML99_INC(acc)))
// } (ML99_mod_IMPL)

// } (Arithmetical operators)

#define ML99_assertIsNat_IMPL(x)                                                                   \
    ML99_PRIV_IF(                                                                                  \
        ML99_PRIV_NAT_EQ(x, x),                                                                    \
        ML99_QUOTE(ML99_PRIV_EMPTY()),                                                                      \
        ML99_PRIV_ASSERT_IS_NAT_FATAL(x, ML99_NAT_MAX))

// clang-format off
#define ML99_PRIV_ASSERT_IS_NAT_FATAL(x, max) ML99_fatal(ML99_assertIsNat, x must be within [0; max])
// clang-format on

// Arity specifiers {

#define ML99_inc_ARITY              1
#define ML99_dec_ARITY              1
#define ML99_natMatch_ARITY         2
#define ML99_natMatchWithArgs_ARITY 3
#define ML99_natEq_ARITY            2
#define ML99_natNeq_ARITY           2
#define ML99_greater_ARITY          2
#define ML99_greaterEq_ARITY        2
#define ML99_lesser_ARITY           2
#define ML99_lesserEq_ARITY         2
#define ML99_add_ARITY              2
#define ML99_sub_ARITY              2
#define ML99_mul_ARITY              2
#define ML99_div_ARITY              2
#define ML99_divChecked_ARITY       2
#define ML99_mod_ARITY              2
#define ML99_add3_ARITY             3
#define ML99_sub3_ARITY             3
#define ML99_mul3_ARITY             3
#define ML99_div3_ARITY             3
#define ML99_min_ARITY              2
#define ML99_max_ARITY              2
#define ML99_assertIsNat_ARITY      1
// } (Arity specifiers)

#endif // DOXYGEN_IGNORE

#endif // ML99_NAT_H
