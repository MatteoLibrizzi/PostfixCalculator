#ifndef _types_
#define _types_

#include "stack.h"

typedef struct calculator {
    StackPtr operands;
} Calculator;
typedef Calculator* CalculatorPtr;

typedef int (*calculatorFunction)(CalculatorPtr c);

#endif