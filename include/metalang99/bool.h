/**
 * @file
 * Boolean algebra.
 */

#ifndef ML99_BOOL_H
#define ML99_BOOL_H

#include <metalang99/priv/bool.h>
#include <metalang99/priv/tuple.h>

#include <metalang99/lang.h>

/**
 * Truth.
 */
#define ML99_true(...) ML99_callUneval(ML99_true, )

/**
 * Falsehood.
 */
#define ML99_false(...) ML99_callUneval(ML99_false, )

/**
 * Logical negation.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/bool.h>
 *
 * // 1
 * ML99_not(ML99_QUOTE(0))
 *
 * // 0
 * ML99_not(ML99_QUOTE(1))
 * @endcode
 */
#define ML99_not(x) ML99_call(ML99_not, x)

/**
 * Logical conjunction.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/bool.h>
 *
 * // 0
 * ML99_and(ML99_QUOTE(0), ML99_QUOTE(0))
 *
 * // 0
 * ML99_and(ML99_QUOTE(0), ML99_QUOTE(1))
 *
 * // 0
 * ML99_and(ML99_QUOTE(1), ML99_QUOTE(0))
 *
 * // 1
 * ML99_and(ML99_QUOTE(1), ML99_QUOTE(1))
 * @endcode
 */
#define ML99_and(x, y) ML99_call(ML99_and, x, y)

/**
 * Logical inclusive OR.
 *
 * # Examples
 * @code
 * #include <metalang99/bool.h>
 *
 * // 0
 * ML99_or(ML99_QUOTE(0), ML99_QUOTE(0))
 *
 * // 1
 * ML99_or(ML99_QUOTE(0), ML99_QUOTE(1))
 *
 * // 1
 * ML99_or(ML99_QUOTE(1), ML99_QUOTE(0))
 *
 * // 1
 * ML99_or(ML99_QUOTE(1), ML99_QUOTE(1))
 * @endcode
 */
#define ML99_or(x, y) ML99_call(ML99_or, x, y)

/**
 * Logical exclusive OR.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/bool.h>
 *
 * // 0
 * ML99_xor(ML99_QUOTE(0), ML99_QUOTE(0))
 *
 * // 1
 * ML99_xor(ML99_QUOTE(0), ML99_QUOTE(1))
 *
 * // 1
 * ML99_xor(ML99_QUOTE(1), ML99_QUOTE(0))
 *
 * // 0
 * ML99_xor(ML99_QUOTE(1), ML99_QUOTE(1))
 * @endcode
 */
#define ML99_xor(x, y) ML99_call(ML99_xor, x, y)

/**
 * Tests @p x and @p y for equality.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/bool.h>
 *
 * // 1
 * ML99_boolEq(ML99_QUOTE(0), ML99_QUOTE(0))
 *
 * // 0
 * ML99_boolEq(ML99_QUOTE(0), ML99_QUOTE(1))
 *
 * // 0
 * ML99_boolEq(ML99_QUOTE(1), ML99_QUOTE(0))
 *
 * // 1
 * ML99_boolEq(ML99_QUOTE(1), ML99_QUOTE(1))
 * @endcode
 */
#define ML99_boolEq(x, y) ML99_call(ML99_boolEq, x, y)

/**
 * Matches @p x against the two cases: if it is 0 or 1.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/bool.h>
 *
 * #define MATCH_1_IMPL() ML99_QUOTE(Billie)
 * #define MATCH_0_IMPL() ML99_QUOTE(Jean)
 *
 * // Billie
 * ML99_boolMatch(ML99_QUOTE(1), ML99_QUOTE(MATCH_))
 *
 * // Jean
 * ML99_boolMatch(ML99_QUOTE(0), ML99_QUOTE(MATCH_))
 * @endcode
 *
 * @note This function calls @p f with #ML99_call, so no partial application occurs, and so
 * arity specifiers are not needed.
 */
#define ML99_boolMatch(x, matcher) ML99_call(ML99_boolMatch, x, matcher)

/**
 * The same as #ML99_boolMatch but provides additional arguments to all branches.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/bool.h>
 *
 * #define MATCH_1_IMPL(x, y, z) ML99_QUOTE(Billie ~ x y z)
 * #define MATCH_0_IMPL(x, y, z) ML99_QUOTE(Jean ~ x y z)
 *
 * // Billie ~ 1 2 3
 * ML99_boolMatchWithArgs(ML99_QUOTE(1), ML99_QUOTE(MATCH_), ML99_QUOTE(1, 2, 3))
 *
 * // Jean ~ 1 2 3
 * ML99_boolMatchWithArgs(ML99_QUOTE(0), ML99_QUOTE(MATCH_), ML99_QUOTE(1, 2, 3))
 * @endcode
 */
#define ML99_boolMatchWithArgs(x, matcher, ...)                                                    \
    ML99_call(ML99_boolMatchWithArgs, x, matcher, __VA_ARGS__)

/**
 * If @p cond is true, evaluates to @p x, otherwise @p y.
 *
 * # Examples
 *
 * @code
 * #include <metalang99/bool.h>
 *
 * // 123
 * ML99_if(ML99_QUOTE(1), ML99_QUOTE(123), ML99_QUOTE(18))
 *
 * // 18
 * ML99_if(ML99_QUOTE(0), ML99_QUOTE(123), ML99_QUOTE(18))
 * @endcode
 */
#define ML99_if(cond, x, y) ML99_call(ML99_if, cond, x, y)

/**
 * The plain version of #ML99_if.
 *
 * This macro can imitate lazy evaluation: `ML99_IF(<cond>, <term>, <another-term>)` will expand to
 * one of the two terms, which can be evaluated further; if `<cond>` is 0, then `<term>` will
 * **not** be evaluated, and the same with `<another-term>`.
 *
 * @note @p x and @p y can possibly expand to commas. It means that you can supply `ML99_TERMS(...)`
 * as a branch, for example.
 */
#define ML99_IF(cond, x, y) ML99_PRIV_UNTUPLE(ML99_PRIV_IF(cond, (x), (y)))

#define ML99_TRUE(...)  1
#define ML99_FALSE(...) 0

#define ML99_NOT(x)        ML99_PRIV_NOT(x)
#define ML99_AND(x, y)     ML99_PRIV_AND(x, y)
#define ML99_OR(x, y)      ML99_PRIV_OR(x, y)
#define ML99_XOR(x, y)     ML99_PRIV_XOR(x, y)
#define ML99_BOOL_EQ(x, y) ML99_PRIV_BOOL_EQ(x, y)

#ifndef DOXYGEN_IGNORE

#define ML99_true_IMPL(...)  ML99_QUOTE(ML99_TRUE())
#define ML99_false_IMPL(...) ML99_QUOTE(ML99_FALSE())

#define ML99_not_IMPL(x)       ML99_QUOTE(ML99_NOT(x))
#define ML99_and_IMPL(x, y)    ML99_QUOTE(ML99_AND(x, y))
#define ML99_or_IMPL(x, y)     ML99_QUOTE(ML99_OR(x, y))
#define ML99_xor_IMPL(x, y)    ML99_QUOTE(ML99_XOR(x, y))
#define ML99_boolEq_IMPL(x, y) ML99_QUOTE(ML99_BOOL_EQ(x, y))

#define ML99_boolMatch_IMPL(x, matcher)              ML99_callUneval(matcher##x, )
#define ML99_boolMatchWithArgs_IMPL(x, matcher, ...) ML99_callUneval(matcher##x, __VA_ARGS__)

#define ML99_if_IMPL(cond, x, y) ML99_QUOTE(ML99_PRIV_IF(cond, x, y))

// Arity specifiers {

#define ML99_true_ARITY              1
#define ML99_false_ARITY             1
#define ML99_not_ARITY               1
#define ML99_and_ARITY               2
#define ML99_or_ARITY                2
#define ML99_xor_ARITY               2
#define ML99_boolEq_ARITY            2
#define ML99_boolMatch_ARITY         2
#define ML99_boolMatchWithArgs_ARITY 3
#define ML99_if_ARITY                3
// } (Arity specifiers)

#endif // DOXYGEN_IGNORE

#endif // ML99_BOOL_H
