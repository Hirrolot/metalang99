#ifndef epEval_MACHINE_H
#define epEval_MACHINE_H

#include <epilepsy/eval/acc.h>
#include <epilepsy/eval/config.h>
#include <epilepsy/eval/rec/control.h>

#define EPILEPSY_PRIV_EVAL_MACHINE_REDUCE(config, ...)                                             \
    EPILEPSY_PRIV_REC_CONTINUE(EPILEPSY_PRIV_EVAL_MATCH, (config), __VA_ARGS__)

#define EPILEPSY_PRIV_EVAL_MACHINE_CALL_K(k, k_cx, acc)                                            \
    EPILEPSY_PRIV_REC_CONTINUE(k, k_cx, EPILEPSY_PRIV_EVAL_ACC_UNWRAP(acc))

#endif // epEval_MACHINE_H
