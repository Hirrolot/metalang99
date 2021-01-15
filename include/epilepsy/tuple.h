/**
 * @file
 * Tuple types.
 *
 * Tuples types are essentially Cons-lists. The common pattern is to define a tuple type constructor
 * and indices of corresponding fields:
 *
 * [<a
 * href="https://github.com/Hirrolot/epilepsy/blob/master/examples/rectangle.c">examples/rectangle.c</a>]
 * @include rectangle.c
 */

#ifndef EPILEPSY_TUPLE_H
#define EPILEPSY_TUPLE_H

#include <epilepsy/list.h>

// Desugaring {
/**
 * Constructs an instance of a tuple type.
 *
 * The same as #EPILEPSY_list.
 */
#define EPILEPSY_tuple(...) EPILEPSY_call(EPILEPSY_tuple, __VA_ARGS__)

/**
 * Extracts a field of a tuple type.
 *
 * The same as #EPILEPSY_listGet.
 */
#define EPILEPSY_get(tuple, i) EPILEPSY_call(EPILEPSY_get, tuple i)
// }

#ifndef DOXYGEN_IGNORE

// Implementation {
#define EPILEPSY_tuple_IMPL(...)    EPILEPSY_list(v(__VA_ARGS__))
#define EPILEPSY_get_IMPL(tuple, i) EPILEPSY_listGet(v(tuple), v(i))
// }

// Arity specifiers {
#define EPILEPSY_tuple_ARITY 1
#define EPILEPSY_get_ARITY   2
// }

// Aliases {
#ifndef EPILEPSY_NO_SMALL_PREFIX

#define E_tuple EPILEPSY_tuple
#define E_get   EPILEPSY_get

#endif // EPILEPSY_NO_SMALL_PREFIX
// }

#endif // DOXYGEN_IGNORE

#endif // EPILEPSY_TUPLE_H