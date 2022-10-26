#include "utils.h"
#include "stack.h"
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*the check for the number of operands is done outside*/

int pCommand(CalculatorPtr calculator) {
    int a;
    a = stack_pop(calculator->operands);
    stack_push(calculator->operands, a);
    printf("    %d\n", a);
    return 0;
}

int aCommand(CalculatorPtr calculator) {
    stack_print(calculator->operands);
    return 0;
}

int cCommand(CalculatorPtr calculator) {
    while (!stack_empty(calculator->operands)) {
        stack_pop(calculator->operands);
    }
    printf("    Emptied\n");
    return 0;
}

int rCommand(CalculatorPtr calculator) {
    int a, b;
    a = stack_pop(calculator->operands);
    b = stack_pop(calculator->operands);
    stack_push(calculator->operands, a);
    stack_push(calculator->operands, b);
    return 0;
}


int sumOperator(CalculatorPtr calculator) {
    int a, b;
    a = stack_pop(calculator->operands);
    b = stack_pop(calculator->operands);
    stack_push(calculator->operands, b + a);
    return 0;
}

int subOperator(CalculatorPtr calculator) {
    int a, b;
    a = stack_pop(calculator->operands);
    b = stack_pop(calculator->operands);
    stack_push(calculator->operands, b - a);
    return 0;
}

int mulOperator(CalculatorPtr calculator) {
    int a, b;
    a = stack_pop(calculator->operands);
    b = stack_pop(calculator->operands);
    stack_push(calculator->operands, b * a);
    return 0;
}

int divOperator(CalculatorPtr calculator) {
    int a, b;
    a = stack_pop(calculator->operands);
    if (a == 0) {
        stack_push(calculator->operands, a);
        fprintf(stderr, "   Can't divide by 0\n");
        return -1;
    }
    b = stack_pop(calculator->operands);
    stack_push(calculator->operands, b / a);
    return 0;
}

int modOperator(CalculatorPtr calculator) {
    int a, b;
    a = stack_pop(calculator->operands);
    if (a == 0) {
        stack_push(calculator->operands, a);
        fprintf(stderr, "   Can't divide by 0\n");
        return -1;
    }
    b = stack_pop(calculator->operands);
    stack_push(calculator->operands, b % a);
    return 0;
}

int facOperator(CalculatorPtr calculator) {
    int a, n, b;
    a = 1;
    n = stack_pop(calculator->operands);
    if (n < 0) {
        stack_push(calculator->operands, n);
        fprintf(stderr, "   Factorial not defined for negative numbers\n");
        return -1;
    }
    for (b = 1; b <= n; b++) {
        a *= b;
    }
    stack_push(calculator->operands, a);
    return 0;
}

int expOperator(CalculatorPtr calculator) {
    int a, b;
    a = stack_pop(calculator->operands);
    b = stack_pop(calculator->operands);
    stack_push(calculator->operands, (int)pow(b, a));
    return 0;
}


int isOperand(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '!' || c == '^';
}

int isCommand(char c) {
    return c == 'p' || c == 'c' || c == 'a' || c == 'r';
}
