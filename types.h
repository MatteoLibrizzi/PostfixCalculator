#ifndef _types_
#define _types_

typedef struct node {
    int value;
    struct node * next;
} Node;
typedef Node* NodePtr;

typedef struct stack {
    NodePtr top;
    int size;
} Stack;
typedef Stack* StackPtr;

typedef struct calculator {
    StackPtr operands;
} Calculator;
typedef Calculator* CalculatorPtr;

typedef int (*calculatorFunction)(CalculatorPtr c);

#endif